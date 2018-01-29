#include "Entity.h"

/*
---ENTITY---
*/
Entity::Entity() : handle(0) {};

int Entity::getHandle() const
{
	return handle;
}

void Entity::setHandle(int handle)
{
	this->handle = handle;
}

/*
---VISUAL---
*/
Visual::Visual(Camera * camera, std::string path, float z, float width, float height)
:
	mesh(new TexRect(camera, path, 0, 0, z, width, height))
{ }

void Visual::render()
{
	mesh->render();
}

void Visual::renderPos(float x, float y)
{
	mesh->setPosition(x, y);
	mesh->render();
}

/*
---TERRAIN---
*/
Terrain::Terrain(Camera * camera, std::string path, float z, float width, float height, bool solid)
:
	Visual(camera, path, z, width, height),
	solid(solid)
{ }

bool Terrain::isSolid()
{
	return solid;
}

void Terrain::setSolid(bool solid)
{
	this->solid = solid;
}

/*
---PHYSICAL---
*/
Physical::Physical(Camera * camera, std::string path, float z, float width, float height)
:
	Visual(camera, path, z, width, height),
	gravity(6),
	velocity(glm::vec3(0, 0, 0))
{ }

glm::vec3 Physical::getVelocity()
{
	return velocity;
}

void Physical::setVelocity(glm::vec3 velocity)
{
	this->velocity = velocity;
}

void Physical::setVelX(float x)
{
	velocity.x = x;
}

void Physical::setVelY(float y)
{
	velocity.y = y;
}

void Physical::setVelZ(float z)
{
	velocity.z = z;
}

float Physical::getGravity()
{
	return gravity;
}

void Physical::setGravity(float gravity)
{
	this->gravity = gravity;
}

/*
---COLLIDABLE---
*/
Collidable::Collidable(Camera * camera, std::string path, float z, float texWidth, float texHeight, float width, float height)
:
	Physical(camera, path, z, texWidth, texHeight),
	hitbox(new AABB(getPosition().x, getPosition().y, width, height))
{ }

AABB* Collidable::getHitbox()
{
	return hitbox;
}