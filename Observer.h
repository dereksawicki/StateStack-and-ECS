#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

#include "Event.h"

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(Event* event) = 0;
};


#endif