#ifndef __TEXTURE_H_
#define __TEXTURE_H_

#include <GL/glew.h>
#include <string>

class Texture
{
public:
	Texture(std::string path);
	~Texture();
	void bind();
	void unbind();
private:
	GLuint tex;
	int id, width, height;
};

#endif