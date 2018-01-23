#ifndef __STATISTICS_H_
#define __STATISTICS_H_

#include "Observer.h"

class Statistics : public Observer
{
public:
	Statistics();
	virtual void onNotify(const GameActor &actor, int statEvent);
	enum StatTypes
	{
		EVENT_ACTION
	};
};

#endif