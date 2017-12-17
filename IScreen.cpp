#include "IScreen.h"

IScreen::IScreen(ScreenStack& screenstack, Context context)
	: mContext(context)
{
	mScreenStack = &screenstack;
}

void IScreen::requestScreenPush(unsigned int screen_id)
{
	mScreenStack->pushScreen(screen_id);
}

void IScreen::requestScreenPop()
{
	mScreenStack->popScreen();
}

Context& IScreen::getContext()
{
	return mContext;
}