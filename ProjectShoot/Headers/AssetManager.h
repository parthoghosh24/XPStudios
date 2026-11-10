#pragma once
#include <Utility.h>
#include <SFML/Graphics.hpp>
#include <unordered_map>
/*
* This class would be responsible for processing all assets in this game.
* We would be requiring various assets like textures, audio, font, etc and this manager would be able to handle all.
* 
* 
*/
class AssetManager
{
private:
	AssetManager() = default;

	// This map is required to hold all the texture in memory till the asset manager is in memory.
	// Once a texture has been loaded, that could stay in this map and we could access it without loading it again.
	std::unordered_map<std::string, sf::Texture> mTextures;

public:
	AssetManager(const AssetManager&) = delete; // No copy constructor allowed
	AssetManager& operator=(const AssetManager&) = delete; // No assignment operator allowed

	//Singleton method via which we will access the asset manager
	static AssetManager& GetInstance() {
		static AssetManager instance;
		return instance;
	}

	sf::Texture& GetTexture(const std::string& textureName);

};