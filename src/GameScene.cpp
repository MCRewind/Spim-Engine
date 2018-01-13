#include "GameScene.h"

GameScene::GameScene(Window* window, Camera* camera)
	: Scene(window, camera),
	inputHandler(new InputHandler(window)),
	rect(new ColRect(camera, 0, 1, 1, 1, 10, 10, 0, 100, 100)),
	actor(new GameActor()),
	world(new World(camera, 16, 16))
{
	world->generateTerrain();
}

void GameScene::update()
{
	rect->setPosition(actor->getPosition());
	Command* command = inputHandler->handleInput();
	if (command)
		command->execute(*actor);
}

void GameScene::render()
{
	rect->render();
	world->render();
}

void GameScene::setActive()
{

}

GameScene::~GameScene() {}