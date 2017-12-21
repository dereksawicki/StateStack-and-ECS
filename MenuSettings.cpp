#include "MenuSettings.h"
#include "MenuScreen.h"

#include <iostream>

MenuSettings::MenuSettings(ScreenStack& screenStack, Context context)
	: IScreen(screenStack, context)
	, mText("", *getContext().font, 24)
{
	mText.setFillColor(getContext().colorScheme->Color(ColorScheme::COLOR::Primary));

	mHeaderText = "Settings";

	initOptions();
	initInputController();

	switch (getContext().controlScheme->getScheme())
	{
	case ControlScheme::SCHEME::Arrows:
		mApplied = MenuSettings::OPTION::Arrows;
		break;
	case ControlScheme::SCHEME::WASD:
		mApplied = MenuSettings::OPTION::WASD;
		break;
	}
}

void MenuSettings::initOptions() {

	mOptions[MenuSettings::OPTION::Arrows].mLabel = "Arrow Keys";
	mOptions[MenuSettings::OPTION::Arrows].mFnc = [this]() {
		getContext().controlScheme->setScheme(ControlScheme::Arrows);
		mApplied = MenuSettings::OPTION::Arrows;
	};

	mOptions[MenuSettings::OPTION::WASD].mLabel = "WASD";
	mOptions[MenuSettings::OPTION::WASD].mFnc = [this]() { 
		getContext().controlScheme->setScheme(ControlScheme::WASD);
		mApplied = MenuSettings::OPTION::WASD;
	};

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
	actionMap[InputController::ACTION::Option] = [this]()
	{
		if (getContext().colorScheme->getScheme() == ColorScheme::SCHEME::Light)
		{
			getContext().colorScheme->setScheme(ColorScheme::SCHEME::Dark);
		}
		else
		{
			getContext().colorScheme->setScheme(ColorScheme::SCHEME::Light);
		}
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
	getContext().window->clear(getContext().colorScheme->Color(ColorScheme::COLOR::Background));

	mText.setFillColor(getContext().colorScheme->Color(ColorScheme::COLOR::Primary));
	// Draw header Text
	mText.setString(mHeaderText);
	mText.setPosition(320, 300);
	getContext().window->draw(mText);

	// Toggle color option
	mText.setString("Press 'M' To toggle color scheme");
	mText.setPosition(50, 500);
	getContext().window->draw(mText);

	// Draw each option
	for (int i = 0; i < SELECTIONS; i++) {
		mText.setString(mOptions[i].mLabel);
		mText.setPosition(50.f, 300.f + 30.f * i);
		mText.setFillColor(getContext().colorScheme->Color(ColorScheme::COLOR::Primary));

		if (i == mSelected) 
		{
			mText.setPosition(70.f, 300.f + 30.f * i);
		} 

		if (i == mApplied) 
		{
			mText.setFillColor(getContext().colorScheme->Color(ColorScheme::COLOR::Secondary));
		}

		getContext().window->draw(mText);
	}
}