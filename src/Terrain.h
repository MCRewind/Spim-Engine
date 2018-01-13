#ifndef __TERRAIN_H_
#define __TERRAIN_H_

#include "Rect.h"

class Terrain
{
public:
	Terrain();
	Terrain(Camera * camera, std::string path, bool solid, float z, float width, float height);
	void render();
	void renderPos(float x, float y);
	bool isSolid() const;
	void setSolid(bool solid);
private:
	TexRect* mesh;
	bool solid;
};

#endif