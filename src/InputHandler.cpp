#include "InputHander.h"

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
	if (window->isKeyPressed(GLFW_KEY_W)) return buttonW_;
	if (window->isKeyPressed(GLFW_KEY_A)) return buttonA_;
	if (window->isKeyPressed(GLFW_KEY_S)) return buttonS_;
	if (window->isKeyPressed(GLFW_KEY_D)) return buttonD_;

	return NULL;
}

void InputHandler::bindCommand(Command*& target, Command* command)
{
	target = command;
}
