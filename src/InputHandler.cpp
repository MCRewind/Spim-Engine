#include "InputHander.h"

#include <iostream>

InputHandler::InputHandler(Window* window) 
:	window(window), 
	buttonW_(new JumpCommand()),
	buttonA_(new MoveLeftCommand()),
	buttonS_(new EmptyCommand()),
	buttonD_(new MoveRightCommand())
{}

Command* InputHandler::handleInput()
{
	if (window->getKey(GLFW_KEY_W)) return buttonW_;
	if (window->getKey(GLFW_KEY_A)) return buttonA_;
	if (window->getKey(GLFW_KEY_S)) return buttonS_;
	if (window->getKey(GLFW_KEY_D)) return buttonD_;

	return NULL;
}

void InputHandler::bindCommand(Command*& target, Command* command)
{
	target = command;
}
