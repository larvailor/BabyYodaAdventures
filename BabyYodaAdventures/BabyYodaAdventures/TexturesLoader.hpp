#ifndef TEXTURES_LOADER_HPP
#define TEXTURES_LOADER_HPP

#include <string>

#include "Types.hpp"

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

	static std::vector<std::string> getDirectories(const std::string pathToRootDir);
};


#endif
