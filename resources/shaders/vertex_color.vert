#version 460 core

layout(location = 0) in vec3 a_pos;
layout(location = 1) in vec4 a_color;

uniform mat4 localToWorld;
uniform mat4 view;
uniform mat4 projection;

out vec4 v_color;

void main() 
{
	gl_Position = projection * view * localToWorld * vec4(a_pos, 1.0);
	v_color = a_color;
}