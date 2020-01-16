#ifndef COMPONENT_HITBOX_HPP
#define COMPONENT_HITBOX_HPP

class Component_Hitbox
{
private:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	/* A rectangle that represents a hitbox */
	sf::RectangleShape m_hitbox;

	/* 
		An X offset from the sprite origin X position.
		Left top hitbox position X
	*/
	float m_offsetX;

	/*
		An Y offset from the sprite origin Y position.
		Left top hitbox position Y
	*/
	float m_offsetY;

	/* The width of the hitbox in pixels */
	float m_width;

	/* The height of the hitbox in pixels */
	float m_height;

	shared<sf::Sprite> m_sprite;

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Component_Hitbox(shared<sf::Sprite>& sprite, float offsetX, float offsetY, float width, float height);

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Component_Hitbox();

	//-----------------------------------------------
	//		Constructors
	//

		// Getters

	sf::FloatRect getHitboxFloatRect() const;

	//-----------------------------------------------
	//		Update
	//

	/**
		Should be called after Component_Movement, but before collision detection
	*/
	void update();

	//-----------------------------------------------
	//		Render
	//

	void render(shared<sf::RenderTarget>& renderTarget);

	//-----------------------------------------------
	//		Else
	//

	bool intersects(const sf::FloatRect& rect);
};

#endif
