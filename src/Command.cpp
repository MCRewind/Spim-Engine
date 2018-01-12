#include "Command.h"

#include <iostream>

void EmptyCommand::execute(GameActor& actor) { actor.translateY(1); }

void MoveLeftCommand::execute(GameActor& actor) { actor.translateX(-1); }

void MoveRightCommand::execute(GameActor& actor) { actor.translateX(1); }

void JumpCommand::execute(GameActor& actor) { actor.translateY(-1); }