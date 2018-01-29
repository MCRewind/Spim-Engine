#include "Command.h"

#include "Entity.h"

#include <iostream>

void EmptyCommand::execute(GameActor& actor) { }

void MoveDownCommand::execute(GameActor& actor) { actor.translateY(5); }

void MoveLeftCommand::execute(GameActor& actor) { actor.translateX(-5); }

void MoveRightCommand::execute(GameActor& actor) {actor.translateX(5); }

void MoveUpCommand::execute(GameActor& actor) { actor.translateY(-5); }