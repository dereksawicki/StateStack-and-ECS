#include "MenuScreen.h"
#include "AppConstants.h"
#include "MenuHome.h"
#include "MenuSettings.h"

#include <iostream>

MenuScreen::MenuScreen(ScreenStack& screenStack, Context context)
	: IScreen(screenStack, context)
{
	mMenuStack = new ScreenStack(context);

	mMenuStack->registerScreen<MenuHome>(MenuScreen::SCREEN::Home);
	mMenuStack->registerScreen<MenuSettings>(MenuScreen::SCREEN::Settings);

	mMenuStack->pushScreen(MenuScreen::SCREEN::Home);
}

MenuScreen::~MenuScreen()
{
	delete mMenuStack;
}

void MenuScreen::update(sf::Time deltaTime)
{
	mMenuStack->update(deltaTime);
}



void MenuScreen::draw()
{
	mMenuStack->draw();
}