#include "ScreenStack.h"
#include "AppConstants.h"

#include <cassert>

ScreenStack::ScreenStack(Context& context)
	: mContext(context)
{

}


void ScreenStack::update(sf::Time deltaTime)
{
	// update from the top down
	for (std::vector<IScreen*>::reverse_iterator it = mScreenStack.rbegin();
		it != mScreenStack.rend(); ++it)
	{
		(*it)->update(deltaTime);
	}

	executePendingChanges();
}

void ScreenStack::executePendingChanges()
{
	while (!mPendingChanges.empty())
	{
		PendingChange pc = mPendingChanges.front();
		mPendingChanges.pop();

		switch (pc.action) {
		case ACTION::Pop:
		{
			delete mScreenStack.front();
			mScreenStack.pop_back();
			break;
		}
		case ACTION::Push:
		{
			mScreenStack.push_back(createScreen(pc.screenID));
			break;
		}
		case ACTION::Clear:
		{
			mScreenStack.clear();
		}
		}
	}
}

void ScreenStack::draw()
{
	// draw from the bottom up
	for (auto screen : mScreenStack)
	{
		screen->draw();
	}
}



void ScreenStack::pushScreen(unsigned int screenID)
{
	PendingChange pc;
	pc.action = ACTION::Push;
	pc.screenID = screenID;

	mPendingChanges.push(pc);
}

void ScreenStack::popScreen()
{
	PendingChange pc;
	pc.action = ACTION::Pop;
	pc.screenID = AppConst::APP_SCREEN::None;

	mPendingChanges.push(pc);

}

void ScreenStack::clearScreens()
{
}

IScreen* ScreenStack::createScreen(unsigned int screenID)
{
	auto found = mFactories.find(screenID);
	assert(found != mFactories.end());

	return found->second();
}