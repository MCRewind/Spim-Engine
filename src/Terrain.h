#ifndef __TERRAIN_H_
#define __TERRAIN_H_

#include "Rect.h"

class Terrain : public TexRect
{
public:
	Terrain(Camera * camera, std::string path, bool solid, float z, float width, float height);
	bool isSolid() const;
	void setSolid(bool solid);
private:
	bool solid;
};

#endif