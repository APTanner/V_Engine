#include "pch.h"

#include "Core/Application.h"

namespace V_Engine
{
	int main()
	{
		Application app = Application();
		app.Run();
		return 0;
	}
}

int main()
{
	return V_Engine::main();
}