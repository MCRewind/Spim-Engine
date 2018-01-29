#ifndef __WORLD_H_
#define __WORLD_H_

#include <vector>

#include "Entity.h"
#include "Player.h"

class World
{
public:
	World(Camera* camera, int width, int height);
	void update();
	void render();
	void generateTerrain();
	const Terrain& getTile(int x, int y) const;
	bool checkCollision(Player *player);
private:
	int width, height;
	int DIMS = 16;
	std::vector<Terrain*> tiles;

	Terrain stoneTerrain, airTerrain;
};

#endif