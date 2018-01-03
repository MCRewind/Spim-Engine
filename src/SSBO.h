#ifndef __SSBO_H_
#define __SSBO_H_

#include <GL\glew.h>

#include "Types.h"

#include <initializer_list>

class SSBO
{
public:
	template <class T>
	SSBO(std::initializer_list<T> data);
	~SSBO();
	void write(int32 program, const char* buffer, GLuint index);
	void bind(GLuint ssbo, int32 index);
};

#endif