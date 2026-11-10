#include "AssetManager.h"

sf::Texture& AssetManager::GetTexture(const std::string& textureName)
{
	auto textureData = mTextures.find(textureName);

	// This we found the texture in the map

	// If the texture has been already loaded, return it instead on instantiating a new one
	if (textureData != mTextures.end())
	{
		return textureData->second;
	}
	// If the texture was not found in the map, we instantiate a new one
	sf::Texture& texture = mTextures[textureName];
	if (!texture.loadFromFile(textureName))
	{
		ERR_LN("Failed to load texture");
	}

	return texture;
}
