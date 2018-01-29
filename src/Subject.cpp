#include "Subject.h"

#include <algorithm>

Subject::Subject()
{
	observers = std::vector<Observer*>();
}

void Subject::addObserver(Observer *observer)
{
	observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer)
{
	//if observers contains observer erase it
	std::vector<Observer*>::iterator i = find(observers.begin(), observers.end(), observer);
	if (i != observers.end())
		observers.erase(i);
}

//notifies this subjects observers of an event
void Subject::notify(GameActor &object, int event)
{
	std::for_each(observers.begin(), observers.end(),  
		[=](Observer * observer)		
		{
			observer->onNotify(object, event);
		}
	);
}