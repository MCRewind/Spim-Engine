#ifndef __SSBO_H_
#define __SSBO_H_

#include <GL\glew.h>

struct buffer_data { };

class SSBO
{
public:
	SSBO(buffer_data data);
	~SSBO();
};

#endif