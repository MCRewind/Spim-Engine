#include "InputHander.h"

#include <iostream>

InputHandler::InputHandler(Window* window)
{
	this->window = window;

	buttonW_ = new JumpCommand();
	buttonA_ = new MoveLeftCommand();
	buttonS_ = new EmptyCommand();
	buttonD_ = new MoveRightCommand();
}

Command* InputHandler::handleInput()
{
	if (window->getKey(GLFW_KEY_W) == 1) return buttonW_;
	if (window->getKey(GLFW_KEY_A) == 1) return buttonA_;
	if (window->getKey(GLFW_KEY_S) == 1) return buttonS_;
	if (window->getKey(GLFW_KEY_D) == 1) return buttonD_;

	return NULL;
}

void InputHandler::bindCommand(Command*& target, Command* command)
{
	target = command;
}
