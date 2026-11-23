#include <FontManager.h>
#include <MainMenu.h>

namespace
{
	const sf::Color NORMAL(60, 60, 60);
	const sf::Color SELECTED(130, 130, 130);
	const sf::Vector2f BUTTON_SIZE(300.f, 80.f);

	// Distance between buttons
	const float BUTTON_SPACING = 120.f;
}

MainMenu::Button::Button(const std::string& text, MenuAction action, sf::Vector2f center, sf::Vector2f size):
	mBox(size),
	mAction(action),
	mButtonLabel(FontManager::GetInstance().GetFont(), text, 40)
{
	mBox.setOrigin(size / 2.f); // center
	mBox.setPosition(center);
	mBox.setFillColor(NORMAL);

	// Get are of the box
	sf::FloatRect labelBound = mButtonLabel.getLocalBounds();

	// Text is centered
	mButtonLabel.setOrigin(labelBound.position + labelBound.size / 2.f);

	mButtonLabel.setPosition(center);

}

MainMenu::MainMenu(sf::Vector2f screenSize):
	mStudioTitle(FontManager::GetInstance().GetFont(), "XP STUDIOS PRESENT", 40),
	mTitle(FontManager::GetInstance().GetFont(), "SPACE ACES", 96)
{
	sf::FloatRect studioNameBounds = mStudioTitle.getLocalBounds();

	// center
	mStudioTitle.setOrigin({ studioNameBounds.position + studioNameBounds.size / 2.f });
	mStudioTitle.setPosition({ screenSize.x / 2.f, screenSize.y * 0.25f - 120.f });


	sf::FloatRect titleBound = mTitle.getLocalBounds();

	// center
	mTitle.setOrigin({ titleBound.position + titleBound.size / 2.f });
	mTitle.setPosition({ screenSize.x / 2.f, screenSize.y * 0.25f });
	

	// center of the screen
	const float cx = screenSize.x / 2.f;
	const float cy = screenSize.y / 2.f;

	mMenuButtons.emplace_back("START", MenuAction::Start, sf::Vector2f(cx, cy), BUTTON_SIZE);
	mMenuButtons.emplace_back("EXIT", MenuAction::Exit, sf::Vector2f(cx, cy + BUTTON_SPACING), BUTTON_SIZE);

}

MenuAction MainMenu::Update(const InputManager& input)
{
	const int count = static_cast<int>(mMenuButtons.size());

	// Handle the up button

	if (input.WasPressed(sf::Keyboard::Key::W) || input.WasPressed(sf::Keyboard::Key::Up))
	{
		mSelected = (mSelected + count  - 1) % count;
	}

	if (input.WasPressed(sf::Keyboard::Key::S) || input.WasPressed(sf::Keyboard::Key::Down))
	{
		mSelected = (mSelected + 1) % count;
	}

	// Paint the buttons based on their states
	for (int idx = 0; idx < count; ++idx)
	{
		bool selected = idx == mSelected;

		mMenuButtons[idx].mBox.setFillColor(selected ? SELECTED : NORMAL);
		mMenuButtons[idx].mButtonLabel.setFillColor(selected ? sf::Color::Yellow : sf::Color::White);
	}

	// Return pressed
	if (input.WasPressed(sf::Keyboard::Key::Enter))
	{
		// return the appropriate action based on menu selection
		return mMenuButtons[mSelected].mAction;
	}


	return MenuAction::None;
}

void MainMenu::Draw(sf::RenderWindow& window)
{
	window.draw(mStudioTitle);
	window.draw(mTitle);

	for(const Button& button: mMenuButtons)
	{
		window.draw(button.mBox);
		window.draw(button.mButtonLabel);
	}
}
