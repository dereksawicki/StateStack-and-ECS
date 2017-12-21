#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include "Observer.h"
#include "Context.h"

#include <map>
#include <functional>

// theres no mouse clicking in this demo
/* input controller catches input events, translates them into actions, distributes actions to listeners. */
class InputController : public Observer
{
public:
	enum ACTION {
		Up,
		Down,
		Select,
		Option
	};

public:
	InputController(const std::map<ACTION, std::function<void()>>& action_bindings, Context& context);
	~InputController();
	
	void onNotify(Event* event);

private:
	std::map<ACTION, std::function<void()>> mActionBindings;
	Context* mContext;
};


#endif