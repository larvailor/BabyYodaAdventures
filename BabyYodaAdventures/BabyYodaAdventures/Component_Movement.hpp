#ifndef COMPONENT_MOVEMENT_HPP
#define COMPONENT_MOVEMENT_HPP

#include <iostream>
#include <fstream>

#include "Types.hpp"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"


class Component_Movement
{
private:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Moving
	//

	float m_maxVelocity;
	sf::Vector2f m_velocity;
	sf::Vector2f m_deceleration;

	//-----------------------------------------------
	//		Sprites
	//

	shared<sf::Sprite> m_sprite;

	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Component_Movement(float maxVelocity, shared<sf::Sprite>& sprite);

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Component_Movement();

	//-----------------------------------------------
	//		Accesors
	//

		// Getters

	sf::Vector2f getVelocity() const;

	//-----------------------------------------------
	//		Update
	//

	void update(const float& frameTime);

	//-----------------------------------------------
	//		Else
	//

	void move(const float dirX, const float dirY, const float& frameTime);

};
#endif
