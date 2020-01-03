#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class State
{
private:
	/////////////////////
	// Variables
	//

	std::vector<std::shared_ptr<sf::Texture>> m_textures;

public:
	/////////////////////
	// Methods
	//

	// Constructors

	State();

	// Destructors

	virtual ~State();

	// Udate

	virtual void update() = 0;

	// Render

	virtual void render() = 0;
};

#endif
