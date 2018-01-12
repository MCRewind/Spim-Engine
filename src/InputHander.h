#ifndef __INPUTHANDLER_H_
#define __INPUTHANDLER_H_

#include "Window.h"
#include "Command.h"
#include "Types.h"

class InputHandler
{
public:
	InputHandler(Window* window);
	Command* handleInput();
	void bindCommand(Command*& target, Command* command);
private:
	Command* buttonW_;
	Command* buttonA_;
	Command* buttonS_;
	Command* buttonD_;

	Window* window;
};

#endif