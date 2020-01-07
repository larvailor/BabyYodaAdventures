#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <fstream>

#include "Types.hpp"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Entity
{
protected:
	/////////////////////
	// Variables
	//

	sf::RectangleShape m_rectShape;
	float m_speed;

	/////////////////////
	// Methods
	//

	// Update

	virtual void handleInput(const float& frameTime); // TODO: now not in use

public:
	/////////////////////
	// Methods
	//

	// Constructors

	Entity();

	// Destructors

	virtual ~Entity();

	// Udate

	virtual void update(const float& frameTime);
	virtual void move(const float& frameTime, const float dirX, const float dirY);

	// Render

	virtual void render(shared<sf::RenderTarget> renderTarget = nullptr);
};

#endif
