#include "ControlScheme.h"

ControlScheme::ControlScheme() 
{
	setScheme(ControlScheme::SCHEME::WASD);
}

void ControlScheme::setScheme(ControlScheme::SCHEME scheme)
{
	switch (scheme) {
	case Arrows:
		mControlScheme[ControlScheme::CONTROL::Down] = sf::Keyboard::Key::Down;
		mControlScheme[ControlScheme::CONTROL::Up] = sf::Keyboard::Key::Up;
		mControlScheme[ControlScheme::CONTROL::Select] = sf::Keyboard::Key::Return;
		mControlScheme[ControlScheme::CONTROL::Option] = sf::Keyboard::Key::M;
		mScheme = ControlScheme::SCHEME::Arrows;
		break;

	case WASD:
		mControlScheme[ControlScheme::CONTROL::Down] = sf::Keyboard::Key::S;
		mControlScheme[ControlScheme::CONTROL::Up] = sf::Keyboard::Key::W;
		mControlScheme[ControlScheme::CONTROL::Select] = sf::Keyboard::Key::Return;
		mControlScheme[ControlScheme::CONTROL::Option] = sf::Keyboard::Key::M;
		mScheme = ControlScheme::SCHEME::WASD;
	}
}

const sf::Keyboard::Key& ControlScheme::Key(CONTROL control)
{
	return mControlScheme[control];
}