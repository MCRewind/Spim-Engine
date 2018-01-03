#version 330 core

layout (std430, binding = 0) buffer camera_data
{
	mat4 proj;
	mat4 view;
	mat4 model;
}

layout (location = 0) in vec3 vertices;

void main() {
	gl_Position = proj * view * model * vec4(vertices, 1.0);
}
