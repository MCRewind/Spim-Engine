#include "Command.h"

#include <iostream>

void EmptyCommand::execute(GameActor& actor) { actor.translateY(5); }

void MoveLeftCommand::execute(GameActor& actor) { actor.translateX(-5); }

void MoveRightCommand::execute(GameActor& actor) {actor.translateX(5); }

void JumpCommand::execute(GameActor& actor) { actor.translateY(-5); }