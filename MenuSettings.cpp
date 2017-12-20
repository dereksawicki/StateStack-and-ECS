#include "MenuSettings.h"
#include "MenuScreen.h"

#include <iostream>

MenuSettings::MenuSettings(ScreenStack& screenStack, Context context)
	: IScreen(screenStack, context)
	, mText("", *getContext().font, 24)
{
	mText.setFillColor(sf::Color::White);


	mHeaderText = "Settings";

	initOptions();
	initInputController();

	mApplied = 1;
}

void MenuSettings::initOptions() {

	mOptions[MenuSettings::OPTION::Arrows].mLabel = "Arrow Keys";
	mOptions[MenuSettings::OPTION::Arrows].mFnc = []() { std::cout << "Arrows" << std::endl; };

	mOptions[MenuSettings::OPTION::WASD].mLabel = "WASD";
	mOptions[MenuSettings::OPTION::WASD].mFnc = []() { std::cout << "WASD" << std::endl; };

	mOptions[MenuSettings::OPTION::Back].mLabel = "Back to Menu";
	mOptions[MenuSettings::OPTION::Back].mFnc = [this]() 
	{
		requestScreenPop();
		requestScreenPush(MenuScreen::SCREEN::Home);
	};
}

void MenuSettings::initInputController() {
	std::map<InputController::ACTION, std::function<void()>> actionMap;
	actionMap[InputController::ACTION::Up] = [this]()
	{
		mSelected = (mSelected - 1 < 0) ? SELECTIONS - 1 : mSelected - 1;
	};
	actionMap[InputController::ACTION::Down] = [this]()
	{
		mSelected = (mSelected + 1) % SELECTIONS;
	};
	actionMap[InputController::ACTION::Select] = [this]()
	{
		mOptions[mSelected].mFnc();
	};

	mInputController = new InputController(actionMap, getContext());
}

MenuSettings::~MenuSettings() 
{
	delete mInputController;
}

void MenuSettings::update(sf::Time detlaTime)
{

}

void MenuSettings::draw()
{
	// Draw header Text
	mText.setString(mHeaderText);
	mText.setPosition(320, 300);
	getContext().window->draw(mText);

	// Draw each option
	for (int i = 0; i < SELECTIONS; i++) {
		mText.setString(mOptions[i].mLabel);
		mText.setPosition(50.f, 300.f + 30.f * i);
		mText.setFillColor(sf::Color::White);

		if (i == mSelected) 
		{
			mText.setPosition(70.f, 300.f + 30.f * i);
		} 

		if (i == mApplied) 
		{
			mText.setFillColor(sf::Color::Green);
		}

		getContext().window->draw(mText);
	}
}