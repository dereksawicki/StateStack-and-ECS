#ifndef ISCREEN_H
#define ISCREEN_H

#include "ScreenStack.h"
#include "Context.h"

#include <SFML/System/Time.hpp>

class ScreenStack;

class IScreen
{
public:
	IScreen(ScreenStack& screenStack, Context context);
	virtual ~IScreen() {};

	virtual void update(sf::Time detlaTime) = 0;
	virtual void draw() = 0;

protected:
	void requestScreenPush(unsigned int screen_id);
	void requestScreenPop();
    Context& getContext();

private:
	ScreenStack* mScreenStack;
	Context mContext;
};

#endif