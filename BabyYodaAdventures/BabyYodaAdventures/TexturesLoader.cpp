#include "stdafx.hpp"
#include "TexturesLoader.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

void TexturesLoader::loadTexture(const std::string pathToFile, std::string key, std::map<std::string, shared<sf::Texture>>& textures)
{
	auto babyYoda = std::make_shared<sf::Texture>();
	if (!babyYoda->loadFromFile(pathToFile))
	{
		std::cout << "ERROR::Scene_Game::initTextures could not load textures " << pathToFile << std::endl;
	}
	textures[key] = std::move(babyYoda);
}
