#ifndef __INPUTHANDLER_H_
#define __INPUTHANDLER_H_

#include "Window.h"
#include "Command.h"
#include "Types.h"

class InputHandler
{
public:
	const enum Modifier
	{
		NOTHING,
		CAMERA,
		PLAYER
	};
	InputHandler(Window* window);
	Command* handleInput();
	void bindCommand(Command*& target, Command* command);
	Modifier getCurrentModifier();
private:
	Modifier currentModifier;

	Command* buttonUp_;
	Command* buttonLeft_;
	Command* buttonDown_;
	Command* buttonRight_;

	Command* buttonW_;
	Command* buttonA_;
	Command* buttonS_;
	Command* buttonD_;

	Window* window;
};

#endif