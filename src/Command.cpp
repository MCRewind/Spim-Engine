#include "Command.h"

#include <iostream>

void EmptyCommand::execute(GameActor& actor) { std::cout << "empty" << std::endl; }

void MoveLeftCommand::execute(GameActor& actor) { std::cout << "left" << std::endl; }

void MoveRightCommand::execute(GameActor& actor) { std::cout << "right" << std::endl; }

void JumpCommand::execute(GameActor& actor) { std::cout << "jump" << std::endl; }