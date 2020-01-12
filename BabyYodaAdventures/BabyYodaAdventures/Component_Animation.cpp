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

void Component_Animation::play(const std::string key, const float& frameTime)
{
	m_animations[key]->play(frameTime);
}

