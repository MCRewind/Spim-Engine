#include "InputHander.h"

#include <iostream>

struct CommandMessage;

InputHandler::InputHandler(Window* window) 
:	window(window), 
	buttonUp_(new MoveUpCommand()),
	buttonLeft_(new MoveLeftCommand()),
	buttonDown_(new MoveDownCommand()),
	buttonRight_(new MoveRightCommand()),
	buttonW_(new MoveUpCommand()),
	buttonA_(new MoveLeftCommand()),
	buttonS_(new MoveDownCommand()),
	buttonD_(new MoveRightCommand()),
	currentModifier(NOTHING)
{}

Command* InputHandler::handleInput()
{
	if (window->getKey(GLFW_KEY_UP))	{ currentModifier = CAMERA;	return buttonUp_; }
	if (window->getKey(GLFW_KEY_LEFT))	{ currentModifier = CAMERA; return buttonLeft_; }
	if (window->getKey(GLFW_KEY_DOWN))	{ currentModifier = CAMERA; return buttonDown_; }
	if (window->getKey(GLFW_KEY_RIGHT)) { currentModifier = CAMERA; return buttonRight_; }

	if (window->getKey(GLFW_KEY_W)) { currentModifier = PLAYER; return buttonW_; }
	if (window->getKey(GLFW_KEY_A)) { currentModifier = PLAYER; return buttonA_; }
	if (window->getKey(GLFW_KEY_S)) { currentModifier = PLAYER; return buttonS_; }
	if (window->getKey(GLFW_KEY_D)) { currentModifier = PLAYER; return buttonD_; }

	currentModifier = NOTHING;

	return NULL;
}

void InputHandler::bindCommand(Command*& target, Command* command)
{
	target = command;
}

InputHandler::Modifier InputHandler::getCurrentModifier()
{
	return currentModifier;
}