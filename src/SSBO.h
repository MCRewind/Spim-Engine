#ifndef __SSBO_H_
#define __SSBO_H_

#include <GL\glew.h>

#include "Types.h"

#include <initializer_list>
#include <vector>

class SSBO
{
public:
	template <class T>
	SSBO(std::vector<T> data);
	~SSBO();
	void swap(int32 program, const char* buffer, GLuint index);
	template <class T>
	void write(std::vector<T> data);
	void bind();
	void bindBase(GLuint ssbo, int32 index);
	GLuint getId();
private:
	GLuint ssbo;
};

#endif