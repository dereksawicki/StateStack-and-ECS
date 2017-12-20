#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "IScreen.h"
#include "MenuHome.h"


#include <SFML/Graphics/Text.hpp>

#include <functional>

class MenuController;

class MenuScreen : public IScreen
{
public:
	enum SCREEN {
		Home
	  , Settings
	};


public:
	MenuScreen(ScreenStack& screenStack, Context context);
	~MenuScreen();

	virtual void update(sf::Time detlaTime);
	virtual void draw();

private:
	ScreenStack* mMenuStack;
};

#endif