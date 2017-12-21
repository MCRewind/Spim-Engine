#include <stdlib.h>

#include "UBO.h"

UBO::UBO(int32 program, const char *block, const GLchar **names)
{
	GLuint blockIndex = glGetUniformBlockIndex(program, block);
	GLint blockSize;

	glGetActiveUniformBlockiv(program, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &blockSize);

	GLubyte *blockBuffer = (GLubyte *) malloc(blockSize);

	//number of blocks / size of buffer
	const GLsizei size = sizeof(names) / sizeof(GLchar*);

	// Query for the offsets of each block variable     
	GLuint indices[size];
	glGetUniformIndices(program, size, names, indices);
	
	GLint offset[size];
	glGetActiveUniformsiv(program, size, indices, GL_UNIFORM_OFFSET, offset);
}

UBO::~UBO()
{

} 