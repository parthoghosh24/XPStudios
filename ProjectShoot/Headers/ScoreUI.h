#pragma once
#include <SFML/Graphics.hpp>
class ScoreUI
{
public:
	ScoreUI();
	ScoreUI(const ScoreUI&) = delete; // copy const not allowed
	ScoreUI& operator=(const ScoreUI&) = delete; // copy assignment operator not allowed

	void SetScore(int score);

	void Draw(sf::RenderWindow& window);

private:	
	sf::Text mLabel;
	sf::Text mScoreValue;	
};
