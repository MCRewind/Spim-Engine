#include "SSBO.h"

#include <iostream>

template <class T>
SSBO::SSBO(std::initializer_list<T> data)
{
	GLuint ssbo = 0;
	glGenBuffers(1, &ssbo);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(data), &data, GL_DYNAMIC_COPY);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

	glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
	GLvoid* p = glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_WRITE_ONLY);
	memcpy(p, &data, sizeof(data))
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}	

void SSBO::write(int32 program, const char* buffer, GLuint index)
{
	GLuint block_index = glGetProgramResourceIndex(program, GL_SHADER_STORAGE_BLOCK, buffer);
	glShaderStorageBlockBinding(program, block_index, index);
}

void SSBO::bind(GLuint ssbo, int32 index)
{
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, ssbo);
}

SSBO::~SSBO()
{	

}