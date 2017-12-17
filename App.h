#ifndef APP_H
#define APP_H


#include "ScreenStack.h"
#include "Context.h"

#include <SFML/Graphics/RenderWindow.hpp>

class App
{
public:
	App();
	~App();

	void init();
	void run();

private:
	void update(sf::Time deltaTime);
	void render();

private:
	Context* mContext;
	sf::RenderWindow mWindow;
	sf::Font mFont;
	ScreenStack* mScreenStack;

};

#endif