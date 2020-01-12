#ifndef COMPONENT_MOVEMENT_HPP
#define COMPONENT_MOVEMENT_HPP

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "Types.hpp"
#include "Directions.hpp"

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

	/* Maximum velocity value */
	float m_maxVelocity;

	/* Vector2f that handles current velocity for X and Y */
	sf::Vector2f m_currVelocity;

	/* Acceleration value */
	float m_acceleration;

	/* Deceleration value */
	float m_deceleration;

	/* Equals to true if velocity X should be updated because of the user input */
	bool m_movedManuallyX;

	/* Equals to true if velocity Y should be updated because of the user input */
	bool m_movedManuallyY;

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

	Component_Movement(float maxVelocity, float reachMaxVelocityTime, float reachZeroVelocityTime, shared<sf::Sprite>& sprite);

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

	/**
		Sets current velocity X or Y using deceleration algorythm if 
		there is no user input.
		Sets m_movedManuallyX and m_movedManuallyY to true if needed
	*/
	void update(const float& frameTime);

	//-----------------------------------------------
	//		Input handling
	//

	/**
		Sets current velocity X or Y value using acceleration algorythm
		because of the user input.
		Sets m_movedManuallyX and m_movedManuallyY to true if needed
	*/
	void move(const DirectionXY& dirX, const DirectionXY& dirY, const float& frameTime);

};
#endif
