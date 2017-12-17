#include "App.h"
#include "AppConstants.h"
#include "TitleScreen.h"
#include "MenuScreen.h"

#

App::App()
	: mWindow(sf::VideoMode(800, 600), "Pong", sf::Style::Close)
{

}

App::~App()
{
	delete mContext;
	delete mScreenStack;
}

void App::init()
{
	mFont.loadFromFile("Media/ARCADECLASSIC.TTF");
	mContext = new Context(mWindow, mFont);
	mScreenStack = new ScreenStack(*mContext);

	// register screens
	mScreenStack->registerScreen<TitleScreen>(AppConst::APP_SCREEN::Title);
	mScreenStack->registerScreen<MenuScreen>(AppConst::APP_SCREEN::Menu);

	mScreenStack->pushScreen(AppConst::APP_SCREEN::Title);

}

void App::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > TIME_PER_FRAME) 
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;
			update(TIME_PER_FRAME);
		}

		render();
	}
}

void App::update(sf::Time dt)
{
	mScreenStack->update(dt);
}

void App::render()
{
	mContext->window->clear();
	mScreenStack->draw();
	mContext->window->display();
}