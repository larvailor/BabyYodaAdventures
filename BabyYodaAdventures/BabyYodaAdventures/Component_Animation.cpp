#include "stdafx.hpp"
#include "Component_Animation.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Component_Animation::Component_Animation(shared<sf::Sprite>& sprite, shared<sf::Texture>& textureSheet) :
	m_sprite(sprite),
	m_textureSheet(textureSheet)
{
}



//-----------------------------------------------
//		Destructors
//

Component_Animation::~Component_Animation()
= default;



//-----------------------------------------------
//		Animation
//

void Component_Animation::addAnimation(
	const std::string key,
	float animationTimer,
	int startFrameX, int startFrameY,
	int framesX, int framesY,
	int width, int height
)
{
	m_animations[key] = std::make_unique<Animation>(
		m_sprite, m_textureSheet,
		animationTimer,
		startFrameX, startFrameY,
		framesX, framesY,
		width, height
		);
}

void Component_Animation::update(const std::string key, const float& frameTime)
{
	if (m_prevAnimationKey != key)
		if (m_animations.count(m_prevAnimationKey))
			m_animations[m_prevAnimationKey]->reset();

	if (m_animations.count(key))
		m_animations[key]->update(frameTime);

	m_prevAnimationKey = key;
}

