#ifndef __RECT_H_
#define __RECT_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_Transform.hpp>
#include "Camera.h"
#include "Texture.h"
#include "Shader.h"
#include "Vao.h"
#include <vector>

class Rect {
public:
	virtual void render() = 0;
	glm::mat4 fullTransform();
	float getX() const;
	float getY() const;
	glm::vec3 getPosition() const;
	float getRotation() const;
	float getWidth() const;
	float getHeight() const;
	glm::vec3 getDims() const;
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setPosition(float x, float y);
	void setPosition(float x, float y, float z);
	void setPosition(glm::vec3 vector);
	void translateX(float x);
	void translateY(float y);
	void translateZ(float z);
	void translate(float x, float y, float z);
	void translate(glm::vec3 vector);
	void setRotation(float angle);
	void rotate(float angle);
	void scale(float scale);
	void scale(float x, float y);
	void setWidth(float width);
	void setHeight(float height);
	void setDims(float width, float height);
	~Rect();
protected:
	Camera * camera;
	glm::vec3 position;
	float rotation, width, height;
	Rect(Camera * camera, float x, float y, float z, float width, float height);
};

class ColRect : public Rect {
public:
	ColRect(Camera * camera, float r, float g, float b, float a, float x, float y, float z, float width, float height);
	void render();
	~ColRect();
private:
	Shader_C * shader;
	static Vao * vao;
	void initVao();
	float r, g, b, a;
};

class TexRect : public Rect {
public:
	TexRect(Camera * camera, std::string path, float x, float y, float z, float width, float height);
	void render();
	~TexRect();
private:
	Texture * texture;
	Shader * shader;
	static Vao * vao;
	void initVao();
};

class MultiRect : public Rect {
public:
	MultiRect(Camera * camera, std::vector<std::string> paths, float x, float y, float z, float width, float height);
	void render();
	void render(int index);
	Shader_T * getShader() const;
	~MultiRect();
private:
	std::vector<Texture *> textures;
	Shader_T * shader;
	static Vao * vao;
	void initVao();
};

#endif