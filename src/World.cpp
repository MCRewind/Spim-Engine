#include "World.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/norm.hpp>

World::World(Camera* camera, int width, int height)
	:
	width(width),
	height(height),
	tiles(std::vector<Terrain*>(width * height)),
	stoneTerrain(camera, "res/textures/terrain/scaffold.png", 0.0f, 16.0f, 16, true),
	airTerrain(camera, "res/textures/terrain/air.png", 0.0f, 16.0f, 16, false)
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
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1 || (x == width / 2 && y == height / 2 + 2))
				tiles[x * height + y] = &stoneTerrain;
			else
				tiles[x * height + y] = &airTerrain;
		}
	int t = 0;
}

const Terrain& World::getTile(int x, int y) const
{
	return *tiles[x * height + y];
}

bool World::checkCollision(Player* player)
{
	AABB * playerHit = player->getHitbox();
	AABB * closest = 0;
	AABB * current = 0;
	glm::vec3 closestLength;
	int minX = floor(player->getX() / DIMS);
	int maxX = ceil(player->getX() / DIMS);
	int minY = floor(player->getY() / DIMS);
	int maxY = ceil(player->getY() / DIMS);
	if (minX >= 0 && maxX < width && minY >= 0 && maxY < height)
	{
		for (uint8 i = minX; i <= maxX; ++i)
		{
			for (uint8 j = minY; j <= maxY; ++j)
			{
				Terrain * curTile = tiles[i * height + j];
				if (curTile->isSolid())
				{
					if (!closest)
					{
						closest = new AABB(i * DIMS, j * DIMS, DIMS, DIMS);
						closestLength = closest->getCenter() + (-playerHit->getCenter());
					}
					else
					{
						if (current)
							delete current;
						current = new AABB(i * DIMS, j * DIMS, DIMS, DIMS);
						glm::vec3 curLength = current->getCenter() + (-playerHit->getCenter());
						if (glm::length2(curLength) < glm::length2(closestLength))
						{
							closestLength = curLength;
							delete closest;
							closest = current;
							current = 0;
						}
					}
				}
			}
		}
	}
	bool ret = false;
	if (closest)
	{
		if (closest->collides(playerHit))
		{
			glm::vec3 transform = closest->getTransform(playerHit);
			if ((player->getVelocity().y < 0 && transform.y < 0) || (player->getVelocity().y > 0 && transform.y > 0))
			{
				transform.x = closest->getTransformX(playerHit);
				transform.y = 0;
			}
			else if ((player->getVelocity().x < 0 && transform.x < 0) || (player->getVelocity().x > 0 && transform.x > 0))
			{
				transform.y = closest->getTransformY(playerHit);
				transform.x = 0;
			}
			player->translate(transform.x, transform.y, transform.z);
			player->alignHitbox();
			if (transform.y < 0)
				player->hitBottom();
			else if (transform.x > 0)
				player->hitLeft();
			else if (transform.x < 0)
				player->hitRight();
			else
				player->hitTop();
			ret = true;
		}
		if (current)
			delete current;
		delete closest;
	}
	return ret;
}