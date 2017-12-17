#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "IScreen.h"


#include <SFML/Graphics/Text.hpp>

class MenuScreen : public IScreen
{
public:
	MenuScreen(ScreenStack& screenStack, Context context);
	~MenuScreen();

	virtual void update(sf::Time detlaTime);
	virtual void draw();

private:
	// options UI
	sf::Text mHeaderText;

};

#endif