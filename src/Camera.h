#ifndef __CAMERA_H_
#define __CAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_Transform.hpp>

#include "GameActor.h"

class Camera : public GameActor
{
public:
	Camera(int width, int height);
	~Camera();
	void setDims(int width, int height);
	int getWidth() const;
	int getHeight() const;
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
};

#endif 
