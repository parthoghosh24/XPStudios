#include "ScoreUI.h"
#include <FontManager.h>

ScoreUI::ScoreUI() : 
	mLabel(FontManager::GetInstance().GetFont(), "SCORE: ", 36),
	mScoreValue(FontManager::GetInstance().GetFont(), "0 ", 36)
{
	mLabel.setFillColor(sf::Color::White);
	mScoreValue.setFillColor(sf::Color::Yellow);

	const float margin = 25.0f;
	mLabel.setPosition({ margin, margin });

	sf::FloatRect labelBounds = mLabel.getGlobalBounds();
	float gap = 15.0f;
	// add a gap between label and value
	mScoreValue.setPosition({ labelBounds.position.x + labelBounds.size.x + gap, margin });

}

void ScoreUI::SetScore(int score)
{
	mScoreValue.setString(std::to_string(score));
}

void ScoreUI::Draw(sf::RenderWindow& window)
{
	window.draw(mLabel);
	window.draw(mScoreValue);
}
