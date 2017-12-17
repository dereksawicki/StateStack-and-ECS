#include "MenuScreen.h"
#include "AppConstants.h"

MenuScreen::MenuScreen(ScreenStack& screenStack, Context context)
	: IScreen(screenStack, context)
	, mHeaderText("Pong Menu", *getContext().font, 24)
{
	mHeaderText.setPosition(sf::Vector2f(350, 300));
	mHeaderText.setFillColor(sf::Color::White);
}

MenuScreen::~MenuScreen()
{

}

void MenuScreen::update(sf::Time deltaTime)
{
}

void MenuScreen::draw()
{
	getContext().window->draw(mHeaderText);
}