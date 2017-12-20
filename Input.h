#ifndef INPUT_H
#define INPUT_H

#include "Subject.h"
#include "InputEvent.h"

#include <SFML/Window/Event.hpp>

#include <iostream>

class Input : public Subject
{
public:
	enum TYPE {
		None
	  , All
	};

public:
	void receiveEvent(sf::Event event) {
		InputEvent* newEvent = new InputEvent(event);
		notify(newEvent, TYPE::All);
		delete newEvent;
	}

};


#endif