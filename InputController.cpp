#include "InputController.h"
#include "InputEvent.h"

InputController::InputController(const std::map<ACTION, std::function<void()>>& action_bindings, Context& context)
{
	context.input->addObserver(this, Input::TYPE::All);
	mActionBindings = action_bindings;
	mContext = &context;
}

InputController::~InputController()
{
	mContext->input->removeObserver(this, Input::TYPE::All);
}

void InputController::onNotify(Event* event)
{
	InputEvent* inputEvent = dynamic_cast<InputEvent*>(event);

	switch (inputEvent->mEvent.type) {
	case sf::Event::KeyPressed:
		if (inputEvent->mEvent.key.code == sf::Keyboard::Key::W) {
			mActionBindings[InputController::ACTION::Up]();
		}
		if (inputEvent->mEvent.key.code == sf::Keyboard::Key::S) {
			mActionBindings[InputController::ACTION::Down]();
		}
		if (inputEvent->mEvent.key.code == sf::Keyboard::Key::Return) {
			mActionBindings[InputController::ACTION::Select]();
		}
	}
}