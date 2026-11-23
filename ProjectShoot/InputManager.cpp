#include "InputManager.h"

void InputManager::Update(bool windowHasFocus)
{
	mPrevious = mKeys;
	mKeys.reset();

	// Don't do anything if this game app is not in focus
	if (!windowHasFocus)
	{
		return;
	}

	for (std::size_t idx = 0; idx < sf::Keyboard::KeyCount; ++idx)
	{
		// Set the key in the bitset which has been pressed
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(idx)))
		{
			mKeys.set(idx);
		}
	}
}

bool InputManager::IsPressed(sf::Keyboard::Key key) const
{
	// This is similar to static_cast<size_t>(InputState::Input::Duck)
	const auto index = static_cast<std::size_t>(key);
	return index < sf::Keyboard::KeyCount && mKeys.test(index);
}

bool InputManager::WasPressed(sf::Keyboard::Key key) const
{
	// This is similar to static_cast<size_t>(InputState::Input::Duck)
	const auto index = static_cast<std::size_t>(key);
	return index < sf::Keyboard::KeyCount && mKeys.test(index) && !mPrevious.test(index);
}
