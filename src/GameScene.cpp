#include "GameScene.h"

GameScene::GameScene(Window* window, Camera* camera) : Scene(window, camera)
{
	this->window = window;
	this->camera = camera;
	SSBO* ssbo = new SSBO();
}

void GameScene::update()
{

}

void GameScene::render()
{

}

void GameScene::setActive()
{

}

GameScene::~GameScene() {}