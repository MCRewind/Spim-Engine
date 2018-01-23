#ifndef __OBSERVER_H_
#define __OBSERVER_H_

#include "GameActor.h"

class Observer
{
public:
	Observer();
	virtual void onNotify(const GameActor &object, int event) = 0;
};

#endif