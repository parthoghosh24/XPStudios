#pragma once
#include <InputManager.h>
#include <SFML/Graphics.hpp>

enum class MenuAction : uint8_t
{
	None,
	Start,
	Exit
};
class MainMenu
{
public:
	MainMenu(sf::Vector2f screenSize);
	MenuAction Update(const InputManager& input);
	void Draw(sf::RenderWindow& window);
private:

	struct Button
	{
		sf::RectangleShape mBox;
		sf::Text mButtonLabel;
		MenuAction mAction;

		Button(const std::string& text, MenuAction action, sf::Vector2f center, sf::Vector2f size);
	};

	sf::Text mStudioTitle;
	sf::Text mTitle;
	std::vector<Button> mMenuButtons;

	// Button index
	int mSelected = 0;
	

};
