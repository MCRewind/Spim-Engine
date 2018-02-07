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
	void hitNothing();
	void alignHitbox();
private:
	Window * window;
	const uint8 SPACE_HELD = 12, WALL_SLIDE = 10, MAX_JUMPS = 1;
	uint8 SPEED = 80, jumps = MAX_JUMPS;
	bool grounded = true, sliding = false, canJump = true;
};

#endif 