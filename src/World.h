#ifndef __WORLD_H_
#define __WORLD_H_

#include <vector>

#include "Terrain.h"

class World
{
public:
	World(Camera* camera, int width, int height);
	void render();
	void generateTerrain();
	const Terrain& getTile(int x, int y) const;
private:
	int width, height;
	std::vector<Terrain*> tiles;

	Terrain stoneTerrain, airTerrain;
};

#endif