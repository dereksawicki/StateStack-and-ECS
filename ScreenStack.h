#ifndef SCREEN_STACK_H
#define SCREEN_STACK_H

#include "IScreen.h"
#include "Context.h"

#include <SFML/System/Time.hpp>

#include <functional>
#include <map>
#include <queue>
#include <vector>

class IScreen;

class ScreenStack
{
public:
	enum ACTION {
		Push
	  , Pop
	  , Clear
	};

public:
	ScreenStack(Context& context);

	void update(sf::Time deltaTime);
	void draw();

	template <typename T>
	void registerScreen(unsigned int screenID);

	void pushScreen(unsigned int screenID);
	void popScreen();
	void clearScreens();

private:
	struct PendingChange {
		ACTION action;
		unsigned int screenID;
	};

private:
	IScreen* createScreen(unsigned int screenID);
	void executePendingChanges();


private:
	std::vector<IScreen*> mScreenStack;
	std::queue<PendingChange> mPendingChanges;
	std::map<unsigned int, std::function<IScreen*()>> mFactories;
	Context mContext;
};

template <typename T>
void ScreenStack::registerScreen(unsigned int screenID)
{
	// use lambda because we're store a function, rather than a new T.
	mFactories[screenID] = [this]()
	{
		return new T(*this, mContext);
	};
}

#endif