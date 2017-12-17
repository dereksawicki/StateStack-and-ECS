#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include "IScreen.h"
#include "Context.h"

#include <SFML/Graphics/Text.hpp>

class TitleScreen : public IScreen
{
public:
	TitleScreen(ScreenStack& screenStack, Context context);

	virtual void update(sf::Time deltaTime);
	virtual void draw();

private:
	sf::Clock mTimer;
	sf::Text mText;
};


#endif