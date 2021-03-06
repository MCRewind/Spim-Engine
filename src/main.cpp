#include <iostream>

#include "Types.h"
#include "Window.h"
#include "Camera.h"
#include "Shader.h"
#include "Scene.h"
#include "GameScene.h"

void update();
void render();
void checkState();
void init();

int state;

const uint16 TARGET_FPS = 60;

uint16 fps;
double deltaTime = 0;

Window * window;
Camera * camera;
Scene * scenes[1];

int main(int32 argc, char *argv[]) {
	init();
	double pastTime = glfwGetTime();
	double curTime, spf = (double)1 / (double)TARGET_FPS;
	uint16 frames = 0;
	double pastSec = pastTime;
	while (!window->shouldClose()) {
		curTime = glfwGetTime();
		if (curTime - pastTime > spf) {
			deltaTime = curTime - pastTime;
			update();
			render();
			pastTime = curTime;
			++frames;
		}
		if (curTime - pastSec > 1) {
			fps = frames;
			std::cout << "FPS: " << fps << std::endl;
			frames = 0;
			++pastSec;
		}
	}
	for (Scene * scene : scenes)
		delete scene;
	delete camera;
	ImGui_ImplGlfwGL3_Shutdown();
	Window::terminate();
	delete window;
	return 0;
}

void init()
{
	window = new Window(0, 0, "Spim Engine", true, true, true, false, false, 8);
	camera = new Camera(window->getWidth(), window->getHeight());
	Shader::init();
	scenes[0] = new GameScene(window, camera);
	state = 0;
}

void update()
{
	checkState();
	window->poll();
	scenes[state]->update();
}

void render()
{
	window->clear();
	scenes[state]->render();
	window->swap();
}

void checkState()
{
	int tempState = scenes[state]->getState();
	if (state != tempState)
	{
		switch (tempState)
		{
		default:
			scenes[tempState]->setActive();
		}
		state = tempState;
	}
}
