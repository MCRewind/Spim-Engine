#include "GameScene.h"

GameScene::GameScene(Window* window, Camera* camera) : Scene(window, camera)
{
	this->window = window;
	this->camera = camera;
	inputHandler = new InputHandler(window);
	rect = new ColRect(camera, 0, 1, 1, 1, 10, 10, 0, 100, 100);
}

void GameScene::update()
{
	Command* command = inputHandler->handleInput();
	GameActor l;
	if (command)
		command->execute(l);
}

void GameScene::render()
{
	rect->render();
}

void GameScene::setActive()
{

}

GameScene::~GameScene() {}