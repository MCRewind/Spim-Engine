#ifndef __GAMESCENE_H_
#define __GAMESCENE_H_

#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene(Window*, Camera*);
	~GameScene();
	void update();
	void render();
	void setActive();
};

#endif