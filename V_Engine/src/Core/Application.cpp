#include "pch.h"
#include "Application.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Events/WindowEvent.h"
#include "imgui/ImGuiManager.h"
#include "imgui/imguiLayer.h"

#include "GLFW/glfw3.h"
#include "GLFW/GLFWManager.h"

#include "Loading/ShaderLoader.h"

#include "Rendering/RenderOperations.h"
#include "Rendering/Renderer.h"

#include "Time.h"
#include "Input.h"

#include "Behavior/CameraController.h"


namespace V_Engine
{

	Application* Application::m_instance = nullptr;

	Application::Application()
	{
		V_ASSERT(m_instance == nullptr, "Can't have multiple applications");
		m_instance = this;

		// initialization
		Log::init();
		m_window = std::unique_ptr<Window>(GLFWManager::InstantiateWindow());
		m_window->SetEventCallback([this](std::unique_ptr<Event> e)
			{
				this->OnEvent(std::move(e));
			});

		m_imguiLayer = new imguiLayer();
		m_layerStack.Push(m_imguiLayer);
		m_layerStack.Push(new CameraController());

		/*float vertices[] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f
		};
		uint32_t indices[] = {
			0, 1, 2
		};*/

		float vertices[] = {
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f,

			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f
		};

		uint32_t indices[] = {
			0,1,2,0,2,3, //top face
			4,5,6,4,6,7, //bottom face
			0,1,4,1,4,5, //left face
			3,2,7,2,7,6, //right face
			0,3,7,0,7,4, //back face
			1,5,6,1,6,2 //front face
		};

		BufferLayout layout = {
			{ BufferDataType::Vector3, "a_pos"},
			{ BufferDataType::Vector4, "a_color"}
		};

		VertexArray* vertexArray = new VertexArray();
		vertexArray->Bind();
		
		vertexArray->SetVertexBuffer(
			std::make_unique<VertexBuffer>(vertices, sizeof(vertices), layout)
		);

		vertexArray->SetElementBuffer(
			std::make_unique<ElementBuffer>(indices, sizeof(indices))
		);

		vertexArray->Unbind();

		m_entity = std::make_unique<Entity>();
		m_entity->SetMesh(std::make_shared<Mesh>(vertexArray));

		m_shader = ShaderLoader::LoadShaderFromFile("vertex_color");

		m_camera = std::make_unique<Camera>(45.0f);
		m_camera->GetTransform().TranslateLocalSpace(glm::vec3(0.0f, 0.0f, 10.0f));
	}

	Application::~Application()
	{
		// delete the window to stop it trying to deallocate itself after GLFW has already
		//   been shut down
		m_window.reset();
		ImGuiManager::Shutdown();
		GLFWManager::Shutdown();
	}

	void Application::Update()
	{
		while (m_running)
		{
			Time::Update();
			m_window->OnUpdate();
			
			for (Layer* layer : m_layerStack)
			{
				layer->OnUpdate();
			}

			RenderOperations::SetClearColor(glm::vec4(.51f, .45f, .9f, 1));
			RenderOperations::ClearColorBuffer();
			RenderOperations::ClearDepthBuffer();

			Renderer::BeginScene();
			m_shader->Bind();

			m_shader->SetProjectionMatrix(m_camera->GetProjection());
			m_shader->SetViewMatrix(m_camera->GetView());
			m_shader->SetLocalToWorldMatrix(m_entity->GetTransform().LocaltoWorld());

			Renderer::SubmitMesh(m_entity->GetMesh());
			Renderer::EndScene();

			m_imguiLayer->StartDrawImGui();
			for (Layer* layer : m_layerStack)
			{
				layer->OnDrawImGui();
			}
			m_imguiLayer->EndDrawImGui();

			HandleLayerUpdates();
			HandleEvents();

			m_window->OnSwapBuffers();
		}
	}

	void Application::OnEvent(std::unique_ptr<Event> event)
	{
		m_eventBuffer.Push(std::move(event));
	}

	bool Application::OnWindowClose(const WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}

	void Application::HandleEvents()
	{
		while (!m_eventBuffer.empty())
		{
			Event& e = m_eventBuffer.front();
			LOG_DEBUG(e.ToString());
			EventDispatcher d{ e };
			d.Dispatch<WindowCloseEvent>([this](const WindowCloseEvent& event) -> bool
				{
					return this->OnWindowClose(event);
				});
			d.Dispatch<WindowResizeEvent>([this](const WindowResizeEvent& event) -> bool
				{
					return this->m_camera->OnScreenResize(event);
				});

			// event should propogate down through all overlays and layers
			for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
			{
				if (e.IsHandled()) { break; }
				(*--it)->OnEvent(e);
			}
			if (!e.IsHandled())
			{
				LOG_WARNING("Event not handled");
			}
			m_eventBuffer.Pop();
		}
	}

	void Application::HandleLayerUpdates()
	{
		// update layers and overlays
		for (Layer* layer : m_layerStack)
		{
			layer->OnUpdate();
		}
	}
}
