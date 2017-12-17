#include "TitleScreen.h"
#include "AppConstants.h"

TitleScreen::TitleScreen(ScreenStack& screenStack, Context context)
	: IScreen(screenStack, context)
	, mText("Made by Derek", *getContext().font, 30)
{
	mTimer.restart();
	mText.setPosition(sf::Vector2f(350, 300));
	mText.setFillColor(sf::Color::White);
}

void TitleScreen::update(sf::Time deltaTime)
{
	if (mTimer.getElapsedTime().asSeconds() > 2.5f)
	{
		requestScreenPop();
		requestScreenPush(AppConst::APP_SCREEN::Menu);
	}
}

void TitleScreen::draw()
{
	getContext().window->draw(mText);
}