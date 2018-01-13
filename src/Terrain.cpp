#include "Terrain.h"

Terrain::Terrain(Camera * camera, std::string path, bool solid, float z, float width, float height)
:
	mesh(new TexRect(camera, path, 0, 0, z, width, height)),
	solid(solid)
{}

void Terrain::render()
{
	mesh->render();
}

void Terrain::renderPos(float x, float y)
{
	mesh->setPosition(x, y);
	mesh->render();
}

bool Terrain::isSolid() const
{
	return solid;
}

void Terrain::setSolid(bool solid)
{
	this->solid = solid;
}