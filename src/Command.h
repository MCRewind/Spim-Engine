#ifndef __COMMAND_H_
#define __COMMAND_H_

#include "GameActor.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(GameActor& actor) = 0;
};

class EmptyCommand : public Command { void execute(GameActor& actor); };
class MoveLeftCommand : public Command { void execute(GameActor& actor); };
class MoveRightCommand : public Command { void execute(GameActor& actor); };
class JumpCommand : public Command { void execute(GameActor& actor); };

#endif