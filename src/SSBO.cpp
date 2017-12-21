#include "SSBO.h"

#include <iostream>

SSBO::SSBO(buffer_data data)
{
	GLuint ssbo = 0;
	glGenBuffers(1, &ssbo);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(data), &data, GL_DYNAMIC_COPY);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);y
}

SSBO::~SSBO()
{

}