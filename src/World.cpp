#include "World.h"

World::World(Camera* camera, int width, int height)
	:
	width(width),
	height(height),
	tiles(std::vector<Terrain*>(width * height)),
	stoneTerrain(camera, "res/textures/terrain/stone.png", true, 0.0f, 16.0f, 16),
	airTerrain(camera, "res/textures/terrain/test.png", false, 0.0f, 16.0f, 16)
{}

void World::render()
{
	for (int x = 0; x < width; ++x)
		for (int y = 0; y < height; ++y)
		{
			tiles[x * height + y]->renderPos(x * 16, y * 16);
		}
}

void World::generateTerrain()
{
	for (int x = 0; x < width; ++x)
		for (int y = 0; y < height; ++y)
		{
			tiles[x * height + y] = &airTerrain;
		}
}

const Terrain& World::getTile(int x, int y) const
{
	return *tiles[x * height + y];
}