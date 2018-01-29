#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "Window.h"
#include "Entity.h"

class Player : public Collidable
{
public:
	Player(Window * window, Camera * camera, std::string path, float z, float texWidth, float texHeight, float width, float height);
	void update();
	void hitTop();
	void hitLeft();
	void hitRight();
	void hitBottom();
	void alignHitbox();
private:
	Window * window;
	uint8 SPEED = 84;
	const uint8 SPACE_HELD = 12, WALL_SLIDE = 10;
	uint16 space = 0;
	bool grounded = true, jump = false;
};

#endif 