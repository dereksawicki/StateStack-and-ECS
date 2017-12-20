#ifndef MENU_HOME_H
#define MENU_HOME_H

#include "IScreen.h"
#include "InputController.h"
#include "MenuSettings.h"

#include <SFML/Graphics/Text.hpp>

#include <functional>

class MenuHome : public IScreen
{
public:
	MenuHome(ScreenStack& screenStack, Context context);
	~MenuHome();

	virtual void update(sf::Time detlaTime) ;
	virtual void draw();

private:
	struct Button {
		std::string mLabel;
		std::function<void()> mFnc;
	};

private:
	static const int SELECTIONS = 3;

private:
	// options UI
	sf::Text mHeaderText;
	sf::Text mButtonText;
	Button mMenuButtons[SELECTIONS];
	short mSelectedOption;

	InputController* mInputController;
};

#endif