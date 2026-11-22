#pragma once
#include <SFML/Graphics.hpp>

class FontManager
{
public:
	FontManager(const FontManager&) = delete; // No copy constructor allowed
	FontManager& operator=(const FontManager&) = delete; // No assignment operator allowed

	//Singleton method via which we will access the asset manager
	static FontManager& GetInstance() {
		static FontManager instance;
		return instance;
	}

	const sf::Font& GetFont() const { return mFont; };

	

private:
	FontManager();

	sf::Font mFont;

	
};
