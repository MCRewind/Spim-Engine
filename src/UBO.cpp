#include <stdlib.h>

#include "UBO.h"

UBO::UBO(int32 program, const char *block, const GLchar **names)
{
	GLuint blockIndex = glGetUniformBlockIndex(program, block);
	GLint blockSize;

	glGetActiveUniformBlockiv(program, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &blockSize);

	GLubyte *blockBuffer = (GLubyte *) malloc(blockSize);

	// Query for the offsets of each block variable

	GLuint indices = sizeof(names) / sizeof(GLchar*);
	glGetUniformIndices(program, 4, names, indices);

	GLint offset[4];
	glGetActiveUniformsiv(program, 4, indices,
		GL_UNIFORM_OFFSET, offset);
}

UBO::~UBO()
{

}