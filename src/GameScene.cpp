#include "GameScene.h"

GameScene::GameScene(Window* window, Camera* camera) : Scene(window, camera)
{
	this->window = window;
	this->camera = camera;
	float vertices[] = {
		1, 0, 0,
		1, 1, 0,
		0, 1, 0,
		0, 0, 0
	};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};
	vao = new Vao(vertices, 4, indices, 6);
	shader = Shader::SHADER_C;
	//ssbo = new SSBO({ 0 });
}

void GameScene::update()
{
	
}

void GameScene::render()
{
	shader->enable();
	shader->setColor(1, 1, 0, 1);
	vao->render();
	shader->disable();
}

void GameScene::setActive()
{

}

GameScene::~GameScene() {}