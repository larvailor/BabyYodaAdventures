#ifndef COMPONENT_ANIMATION_HPP
#define COMPONENT_ANIMATION_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "Types.hpp"

class Component_Animation
{
private:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Inner classes
	//

	class Animation
	{
	public:
		/////////////////////////////////////////////////
		// 
		//		VARIABLES
		//
		/////////////////////////////////////////////////

		shared<sf::Sprite> m_sprite;
		shared<sf::Texture> m_textureSheet;
		float m_oneFrameAnimationTime;
		float m_timer;
		int m_width;
		int m_height;
		sf::IntRect m_startRect;
		sf::IntRect m_currRect;
		sf::IntRect m_endRect;

		/////////////////////////////////////////////////
		// 
		//		METHODS
		//
		////////////////////////////////////////////////

		Animation(
			shared<sf::Sprite>& sprite, shared<sf::Texture>& textureSheet,
			float animationTime,
			int startFrameX, int startFrameY,
			int framesX, int framesY,
			int width, int height
		) :
			m_sprite(sprite),
			m_textureSheet(textureSheet),
			m_oneFrameAnimationTime(animationTime / framesX),
			m_width(width),
			m_height(height),
			m_timer(0.f)
		{
			m_startRect = sf::IntRect(startFrameX * width, startFrameY * height, width, height);
			m_currRect = m_startRect;
			m_endRect = sf::IntRect(framesX * width, framesY * height, width, height);

			m_sprite->setTexture(*m_textureSheet, true);
			m_sprite->setTextureRect(m_startRect);
		}

		//-----------------------------------------------
		//		Update
		//

		void update(const float& frameTime)
		{
			m_timer += frameTime;
			if (m_timer > m_oneFrameAnimationTime)
			{
				m_timer = 0.f;

				if (m_currRect != m_endRect)
				{
					m_currRect.left += m_width;
				}
				else
				{
					reset();
				}

				m_sprite->setTextureRect(m_currRect);
			}
		}

		void reset()
		{
			m_currRect = m_startRect;
		}
	};

	//-----------------------------------------------
	//		Animation
	//

	shared<sf::Sprite> m_sprite;
	std::map<std::string, unique<Animation>> m_animations;
	std::string m_prevAnimationKey;

	//-----------------------------------------------
	//		Resources
	//

		// Textures

	shared<sf::Texture> m_textureSheet;

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Component_Animation(shared<sf::Sprite>& sprite, shared<sf::Texture>& textureSheet);

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Component_Animation();


	//-----------------------------------------------
	//		Animation
	//

	void addAnimation(
		const std::string key,
		float animationTime,
		int startFrameX, int startFrameY,
		int framesX, int framesY,
		int width, int height
	);

	void update(const std::string key, const float& frameTime);
};

#endif
