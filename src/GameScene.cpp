#include "GameScene.h"


/*
TODO:
- Add entity system
	. non-static actors
	. component based
	. shallow and deep prototyping
	. statically allocated linked pools
	. use observers?
	. single templeted spawner class
*/

GameScene::GameScene(Window* window, Camera* camera)
	: Scene(window, camera),
	inputHandler(new InputHandler(window)),
	world(new World(camera, 16, 16)),
	subject(new Subject()),
	statistics(new Statistics()),
	player(new Player(window, camera, "res/textures/terrain/test.png", 0, 16, 16, 16, 16))
{
	world->generateTerrain();
	subject->addObserver(statistics);
	player->setPosition(32, 32);
}

void GameScene::update()
{
	player->update();

	Command* command = inputHandler->handleInput();
	if (command)
	{
		switch (inputHandler->getCurrentModifier())
		{
		case InputHandler::CAMERA:
			command->execute(*camera);
			break;
		}
	}
	if (window->getKey(GLFW_KEY_SLASH))
		camera->zoomi();
	else if (window->getKey(GLFW_KEY_PERIOD))
		camera->zoomo();
	//subject->notify(*actor, Statistics::EVENT_ACTION);
	while (world->checkCollision(player));

	{
		ImGui::Begin("Another Window", 1 ^ 1);
		ImGui::Text("Hello from another window!");
		ImGui::End();
	}
}

void GameScene::render()
{
	player->renderPos(player->getPosition().x, player->getPosition().y);
	world->render();
	ImGui::Render();
}

void GameScene::setActive()
{

}

GameScene::~GameScene() 
{
	subject->removeObserver(statistics);
}