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

	bool left  = window->getKey(GLFW_KEY_A);
	bool right = window->getKey(GLFW_KEY_D);
	bool up	   = window->getKey(GLFW_KEY_W);
	bool down  = window->getKey(GLFW_KEY_S);

	if (right && !left)
	{
		if (grounded)
			setVelX(SPEED);
		else if (getVelocity().x < SPEED) {
			setVelX(getVelocity().x + (SPEED * 0.1));
			if (getVelocity().x > SPEED)
				setVelX(SPEED);
		}
		direction = true;
	}
	if (left && !right) {
		if (grounded)
			setVelX(-SPEED);
		else if (getVelocity().x > -SPEED) {
			setVelX(getVelocity().x - (SPEED * 0.1));
			if (getVelocity().x < -SPEED)
				setVelX(-SPEED);
		}
		direction = true;
	}

	if (!direction && grounded)
		setVelX(0);
	if (window->getKey(GLFW_KEY_SPACE) || window->getKey(GLFW_KEY_W)) {
		if (grounded) {
			jump = true;
			setVelY(-256);
			grounded = false;
			space = 1;
		}
		else if (space > 0 && space < SPACE_HELD && jump)
			setVelY(getVelocity().y - getGravity() * (SPACE_HELD - space + 1) / SPACE_HELD);
		++space;
	}
	else {
		space = 0;
		jump = false;
	}
	setVelY(getVelocity().y + getGravity());

	grounded = false;
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
		setVelY(WALL_SLIDE);
	if (!grounded && space == 1) {
		jump = true;
		setVelX(160);
		setVelY(-140);
	}
}

void Player::hitRight() {
	setVelX(0);
	if (getVelocity().y > WALL_SLIDE)
		setVelY(WALL_SLIDE);
	if (!grounded && space == 1) {
		jump = true;
		setVelX(-160);
		setVelY(-140);
	}
}
void Player::hitBottom()
{
	setVelY(0);
	grounded = true;
}