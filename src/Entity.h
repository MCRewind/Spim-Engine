#ifndef __ENTITY_H_
#define __ENTITY_H_

#include "GameActor.h"
#include "Rect.h"
#include "AABB.h"

class Entity : public GameActor
{
public:
	Entity();
	int getHandle() const;
	void setHandle(int handle);
private:
	int handle;
};

class Visual : public Entity
{
public:
	Visual(Camera * camera, std::string path, float z, float width, float height);
	void render();
	void renderPos(float x, float y);
private:
	TexRect* mesh;
};

class Terrain : public Visual
{
public:
	Terrain(Camera * camera, std::string path, float z, float width, float height, bool solid);
	bool isSolid();
	void setSolid(bool solid);
private:
	bool solid;
};

class Physical : public Visual
{
public:
	Physical(Camera * camera, std::string path, float z, float width, float height);
	glm::vec3 getVelocity();
	void setVelX(float x);
	void setVelY(float y);
	void setVelZ(float z);
	void setVelocity(glm::vec3 velocity);
	float getGravity();
	void setGravity(float gravity);
private:
	float gravity;
	glm::vec3 velocity;
};

class Collidable : public Physical
{
public:
	Collidable(Camera * camera, std::string path, float z, float texWidth, float texHeight, float width, float height);
	AABB * getHitbox();
private:
	AABB * hitbox;
};

#endif 