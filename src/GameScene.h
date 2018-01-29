#ifndef __GAMESCENE_H_
#define __GAMESCENE_H_

#include "Scene.h"
#include "InputHander.h"
#include "Rect.h"
#include "World.h"
#include "Subject.h"
#include "Statistics.h"
#include "Player.h"

class GameScene : public Scene
{
public:
	GameScene(Window*, Camera*);
	~GameScene();
	void update();
	void render();
	void setActive();
	InputHandler* inputHandler;
	World* world;
	Subject* subject;
	Statistics* statistics;
	Player* player;
};

#endif