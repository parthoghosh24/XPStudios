#pragma once
#include <bitset>
#include <SFML/Graphics.hpp>

class InputManager
{
public:
	void Update(bool windowHasFocus);
	bool IsPressed(sf::Keyboard::Key key) const;

	// This is required to restrict the spamming of keys.
	// It behaves like only pressed once/tap rather than a hold
	bool WasPressed(sf::Keyboard::Key key) const;
private:
	std::bitset<sf::Keyboard::KeyCount> mKeys;

	// Here is an example of WasKeyPressed - https://github.com/Krilliac/SparkEngine/wiki/Input-System. This maintains which buttons have been pressed in last frame
	std::bitset<sf::Keyboard::KeyCount> mPrevious;
};