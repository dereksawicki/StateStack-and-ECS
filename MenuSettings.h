#ifndef MENU_SETTINGS
#define MENU_SETTINGS

#include "IScreen.h"
#include "ScreenStack.h"
#include "InputController.h"

#include <SFML/Graphics/Text.hpp>

#include <functional>


/* Menu Settings displays current settings, and allows user to modify them. */
class MenuSettings : public IScreen
{
public:
	enum OPTION {
		Arrows,
		WASD,
		Back
	};

public:
	MenuSettings(ScreenStack& screenStack, Context context);
	~MenuSettings();

	virtual void update(sf::Time detlaTime);
	virtual void draw();

private:
	static const int SELECTIONS = 3;

private:
	struct Option 
	{
		std::string mLabel;
		std::function<void()> mFnc;
	};

private:
	void initInputController();
	void initOptions();

private:
	short mApplied;
	short mSelected;
	sf::Text mText;

	std::string mHeaderText;
	Option mOptions[SELECTIONS];
	InputController* mInputController;
};


#endif