#ifndef __GAMEACTOR_H_
#define __GAMEACTOR_H_

#include <glm/glm.hpp>

class GameActor
{
public:
	GameActor();
	float getX();
	float getY();
	float getZ();
	glm::vec3 getPosition();
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
private:
	glm::vec3 position;
};

#endif