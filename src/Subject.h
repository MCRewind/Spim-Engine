#ifndef __SUBJECT_H_
#define __SUBJECT_H_

#include <vector>

#include "Observer.h"

class Subject
{
public:
	Subject();
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notify(GameActor &object, int event);
private:
	std::vector<Observer*> observers;
	int numObservers;
};

#endif