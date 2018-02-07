#include "Player.h"

#include <iostream>

extern double deltaTime;

Player::Player(Window* window, Camera * camera, std::string path, float z, float texWidth, float texHeight, float width, float height)
:
	Collidable(camera, path, z, texWidth, texHeight, width, height),
	window(window),
	grounded(true)
{ }

void Player::update()
{
	bool direction = false;

	bool left = window->getKey(GLFW_KEY_A);
	bool right = window->getKey(GLFW_KEY_D);
	bool up = window->getKey(GLFW_KEY_W);
	bool down = window->getKey(GLFW_KEY_S);

	if (left && !right)
		setVelX(-SPEED);
	else if (right && !left)
		setVelX(SPEED);
	else
		setVelX(0);

	if (window->getKeyRelease(GLFW_KEY_W))
		canJump = true;

	if (jumps > 0)
	{
		if (up && canJump && (grounded || sliding))
		{
			setVelY(-200);
			--jumps;
			canJump = false;
			grounded = false;
			sliding = false;
		}
	}

	if ((grounded || sliding) && jumps < MAX_JUMPS)
		++jumps;

	setVelY(getVelocity().y + getGravity());

	setPosition(getPosition() + (getVelocity() * (float)deltaTime));
	getHitbox()->setPosition(getPosition());
}

void Player::alignHitbox() 
{
	getHitbox()->setPosition(getPosition());
}

void Player::hitTop()
{
	setVelY(0);
}

void Player::hitLeft() {
	setVelX(0);
	if (getVelocity().y > WALL_SLIDE)
	{
		setVelY(WALL_SLIDE);
	}
	sliding = true;
}

void Player::hitRight() {
	setVelX(0);
	if (getVelocity().y > WALL_SLIDE)
	{
		setVelY(WALL_SLIDE);
	}
	sliding = true;
}

void Player::hitBottom()
{
	setVelY(0);
	grounded = true;
	sliding = false;
}

void Player::hitNothing()
{
	std::cout << "sdgfsdfgsfdg" << std::endl;
}