#ifndef COMPONENT_MOVEMENT_HPP
#define COMPONENT_MOVEMENT_HPP

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

	DirectionX m_currDirectionX;
	DirectionY m_currDirectionY;

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

	/**
		Use this constructor when entity is under player control and should be moved mannually
	*/
	Component_Movement(float maxVelocity, float reachMaxVelocityTime, float reachZeroVelocityTime, shared<sf::Sprite>& sprite);
	
	/**
		Use this constructor when entity should be moved with the same velocity during its all life	
	*/
	Component_Movement(sf::Vector2f startVelocity, shared<sf::Sprite>& sprite);

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Component_Movement();

	//-----------------------------------------------
	//		Accesors
	//

		// Getters

	float getMaxVelocity() const;
	sf::Vector2f getVelocity() const;
	DirectionX getCurrDirectionX() const;
	DirectionY getCurrDirectionY() const;

	//-----------------------------------------------
	//		Update
	//

	/**
		Sets current velocity X or Y using deceleration algorythm if 
		there is no user input.
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
	void move(const DirectionX& dirX, const DirectionY& dirY, const float& frameTime);
	
	/**
		Sets new current velocity X and Y and moves the sprite using it
	*/
	void move(sf::Vector2f newVelocity, const float& frameTime);

	/**
		Stops the sprite
	*/
	void stop();
};
#endif
