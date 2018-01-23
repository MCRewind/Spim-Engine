#include "Statistics.h"

#include <iostream>

Statistics::Statistics() : Observer() {}

void Statistics::onNotify(const GameActor &actor, int statEvent)
{
	switch (statEvent)
	{
	case EVENT_ACTION:
		std::cout << "ACTION" << std::endl;
		break;
	default:
		break;
	}
}