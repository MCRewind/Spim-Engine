#ifndef __UBO_H_
#define __UBO_H_

#include <GL\glew.h>

#include "Types.h"

class UBO
{
public:
	UBO(int32 program, const char* block, const GLchar **names);
	~UBO();
private:
};

#endif