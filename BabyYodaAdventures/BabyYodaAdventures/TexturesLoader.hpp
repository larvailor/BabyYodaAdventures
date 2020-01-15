#ifndef TEXTURES_LOADER_HPP
#define TEXTURES_LOADER_HPP

class TexturesLoader
{
private:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	/**
		A private constructor to disallow creating an instance of this object
	*/
	TexturesLoader() { } 

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	static void loadTexture(const std::string pathToFile, std::string key, std::map<std::string, shared<sf::Texture>>& m_textures);
};


#endif
