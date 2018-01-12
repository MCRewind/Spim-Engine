#ifndef __CAMERA_H_
#define __CAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_Transform.hpp>

class Camera
{
public:
	Camera(int width, int height);
	~Camera();
	void setDims(int width, int height);
	int getWidth() const;
	int getHeight() const;
	void translate(glm::vec3);
	glm::vec3 getPos() const;
	void setPos(glm::vec3);
	float getRotation() const;
	void rotate(float angle);
	void setRotation(float angle);
	glm::mat4 getProjection() const;
	glm::mat4 getView() const;
	float getScale() const;
	void zoomi();
	void zoomo();
private:
	float width, height, rotation, scale;
	glm::mat4 projection;
	glm::vec3 position;
};

#endif 
