#include "SSBO.h"

#include <iostream>

template <class T>
SSBO::SSBO(std::vector<T> data)
{
	ssbo = 0;
	glGenBuffers(1, &ssbo);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(data), &data, GL_DYNAMIC_COPY);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

	bind();
	GLvoid* p = glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_WRITE_ONLY);
	memcpy(p, &data, sizeof(data))
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}	

template <class T>
void SSBO::write(std::vector<T> data)
{
	GLvoid* p = glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_WRITE_ONLY);
	memcpy(p, &data, sizeof(data))
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}

void SSBO::swap(int32 program, const char* buffer, GLuint index)
{
	GLuint block_index = glGetProgramResourceIndex(program, GL_SHADER_STORAGE_BLOCK, buffer);
	glShaderStorageBlockBinding(program, block_index, index);
}

void SSBO::bind()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
}

void SSBO::bindBase(GLuint ssbo, int32 index)
{
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, ssbo);
}

GLuint SSBO::getId()
{
	return ssbo;
}

SSBO::~SSBO()
{	

}