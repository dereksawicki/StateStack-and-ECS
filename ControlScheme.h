#ifndef CONTROL_SCHEME_H
#define CONTROL_SCHEME_H

#include <SFML/Window/Keyboard.hpp>

#include <map>

class ControlScheme
{
public:
	enum SCHEME {
		Arrows,
		WASD
	};

	enum CONTROL {
		Down
	  , Up
	  , Select
	  , Option
	};

public:
	ControlScheme();

	const sf::Keyboard::Key& Key(CONTROL control);
	void setScheme(SCHEME scheme);
	SCHEME getScheme() { return mScheme; };

private:
	std::map<CONTROL, sf::Keyboard::Key> mControlScheme;
	SCHEME mScheme;
};


#endif