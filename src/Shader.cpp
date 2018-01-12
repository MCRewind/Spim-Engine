#include <stdio.h>
#include <fstream>

#include <GL/glew.h>

#include "Shader.h"

Shader_C * Shader::SHADER_C = 0;
Shader_T * Shader::SHADER_T = 0;

Shader::Shader(std::string vert, std::string frag)
{
	uint32 vertId = loadShader(vert, GL_VERTEX_SHADER);
	uint32 fragId = loadShader(frag, GL_FRAGMENT_SHADER);
	program = glCreateProgram();
	glAttachShader(program, vertId);
	glAttachShader(program, fragId);
	glLinkProgram(program);

	int result, length;
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
	if (length > 0) 
	{
		char * message = new char[length + 1];
		glGetProgramInfoLog(program, length, 0, message);
		fprintf(stderr, "%s\n", message);
		delete[] message;
	}

	glDetachShader(program, vertId);
	glDetachShader(program, fragId);

	glDeleteShader(vertId);
	glDeleteShader(fragId);

	
	projLoc = getUniformLoc("proj");
	viewLoc = getUniformLoc("view");
	modelLoc = getUniformLoc("model");
	
}

uint32 Shader::loadShader(std::string path, int32 type)
{
	std::ifstream fin(path, std::ifstream::binary);
	if (fin)
	{
		fin.seekg(0, fin.end);
		int length = fin.tellg();
		fin.seekg(0, fin.beg);

		char * input = new char[length + 1];
		fin.read(input, length);
		input[length] = '\0';

		fin.close();

		uint32 id = glCreateShader(type);
		glShaderSource(id, 1, &input, 0);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		if (length > 0)
		{
			char * message = new char[length + 1];
			glGetShaderInfoLog(id, length, 0, message);
			fprintf(stderr, "%s\n", message);
			delete[] message;
		}

		return id;
		delete[] input;
	}
	else
		fprintf(stderr, "Cannot find shader: %s\n", path);
	return 0;
}

void Shader::init() 
{
	SHADER_C = new Shader_C();
	SHADER_T = new Shader_T();
}

GLint Shader::getUniformLoc(std::string name) const
{
	return glGetUniformLocation(program, name.c_str());
}

void Shader::setProjection(glm::mat4 projection)
{
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Shader::setView(glm::mat4 view)
{
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

void Shader::setModel(glm::mat4 model)
{
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}

void Shader::enable()
{
	glUseProgram(program);
}

void Shader::disable()
{
	glUseProgram(0);
}

Shader::~Shader() 
{
	glDeleteProgram(program);
}

//Shader_C - A shader for drawing 2d messhes with a solid color
Shader_C::Shader_C() : Shader("res/shaders/s_C/vert.vs", "res/shaders/s_C/frag.fs") 
{
	getUniformLocs();
}

void Shader_C::getUniformLocs()
{
	colorLoc = glGetUniformLocation(program, "iColor");
}

void Shader_C::setColor(float r, float g, float b, float a) 
{
	glUniform4f(colorLoc, r, g, b, a);
}

Shader_C::~Shader_C() {}

//Shader_T - A shader for drawing 2d textured meshes
Shader_T::Shader_T() : Shader("res/shaders/s_T/vert.vs", "res/shaders/s_T/frag.fs") {}

Shader_T::~Shader_T() {}