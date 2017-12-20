#include "MenuHome.h"
#include "MenuScreen.h"

#include <iostream>

MenuHome::MenuHome(ScreenStack& screenStack, Context context)
	: IScreen(screenStack, context)
	, mHeaderText("Pong Menu", *getContext().font, 30)
	, mButtonText("", *getContext().font, 24)
{
	mHeaderText.setPosition(sf::Vector2f(320, 300));
	mHeaderText.setFillColor(sf::Color::White);

	Button playButton;
	Button optionsButton;
	Button exitButton;
	playButton.mFnc = []() { std::cout << "Play" << std::endl;  };
	playButton.mLabel = "Play";

	optionsButton.mFnc = [this]() { 
		requestScreenPop();
		requestScreenPush(MenuScreen::SCREEN::Settings);
	};
	optionsButton.mLabel = "Options";

	exitButton.mFnc = [=]() { getContext().window->close(); };
	exitButton.mLabel = "Exit";

	mMenuButtons[0] = playButton;
	mMenuButtons[1] = optionsButton;
	mMenuButtons[2] = exitButton;

	mButtonText.setFillColor(sf::Color::White);

	mSelectedOption = 0;

	std::map<InputController::ACTION, std::function<void()>> actionMap;
	actionMap[InputController::ACTION::Down] = [this]() { mSelectedOption = (mSelectedOption + 1) % SELECTIONS; };
	actionMap[InputController::ACTION::Up] = [this]() { mSelectedOption = (mSelectedOption - 1) < 0 ? SELECTIONS - 1 : mSelectedOption - 1; };
	actionMap[InputController::ACTION::Select] = [this]() { mMenuButtons[mSelectedOption].mFnc();  };

	mInputController = new InputController(actionMap, getContext());
}

MenuHome::~MenuHome()
{
	std::cout << "Menu home destructor" << std::endl;
	delete mInputController;
}

void MenuHome::update(sf::Time deltaTime)
{

}

void MenuHome::draw()
{
	getContext().window->draw(mHeaderText);


	for (int i = 0; i < SELECTIONS; i++)
	{
		mButtonText.setPosition(sf::Vector2f(50, 300 + 30 * i));
		mButtonText.setString(mMenuButtons[i].mLabel);

		if (i == mSelectedOption)
		{
			mButtonText.setPosition(sf::Vector2f(70, 300 + 30 * i));
		}

		getContext().window->draw(mButtonText);
	}

}