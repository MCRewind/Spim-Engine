#include "GameActor.h"

GameActor::GameActor()
{
	position = { 0, 0, 0 };
}

float GameActor::getX() const
{
	return position.x;
};

float GameActor::getY()  const
{
	return position.y;
};

float GameActor::getZ() const
{ 
	return position.z; 
};

glm::vec3 GameActor::getPosition() const
{
	return position; 
};

void GameActor::setX(float x)
{
	position.x = x;
};

void GameActor::setY(float y) 
{
	position.x = y; 
};

void GameActor::setZ(float z)
{
	position.x = z;
};

void GameActor::setPosition(float x, float y) 
{
	position.x = x; 
	position.y = y; 
}

void GameActor::setPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void GameActor::setPosition(glm::vec3 vector)
{
	position = vector;
}

void GameActor::translateX(float x)
{
	position.x += x;
}

void GameActor::translateY(float y)
{
	position.y += y;
}

void GameActor::translateZ(float z)
{
	position.z = z;
}

void GameActor::translate(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
}