#include "Terrain.h"

Terrain::Terrain(Camera * camera, std::string path, bool solid, float z, float width, float height)
:
	TexRect(camera, path, 0, 0, z, width, height),
	solid(solid)
{}

bool Terrain::isSolid() const
{
	return solid;
}

void Terrain::setSolid(bool solid)
{
	this->solid = solid;
}