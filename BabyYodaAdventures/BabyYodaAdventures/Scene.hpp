#ifndef SCENE_HPP
#define SCENE_HPP

#include "Entity.hpp"

class Scene
{
protected:
	/////////////////////
	// Variables
	//

	/* A shared_ptr to a window on which scene is */
	std::shared_ptr<sf::RenderWindow> m_renderWindow;
	std::map<std::string, sf::Keyboard::Key> *m_supportedKeys;
	std::map<std::string, sf::Keyboard::Key> m_keyBinds;
	bool m_close;

	// Mouse positions
	
	sf::Vector2i m_mousePosScreen;
	sf::Vector2i m_mousePosWindow;
	sf::Vector2f m_mousePosView;

	// Resources
		// textures
		
	std::vector<std::shared_ptr<sf::Texture>> m_textures;
	
		// fonts

	std::shared_ptr<sf::Font> m_font;


	/////////////////////
	// Methods
	//

	// Initialization

	virtual void initKeyBinds(std::string pathToConfig);
	virtual void initFont(std::string pathToFont);

	// Udate

	virtual void handleInput(const float &frameTime) = 0;
	virtual void updateMousePositions();

	// Managing scene

	virtual void checkForClose();

public:
	/////////////////////
	// Methods
	//

	// Constructors

	Scene(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys);

	// Destructors

	virtual ~Scene();

	//Accessors
		// getters

	bool needToBeClosed() const;

	// Udate

	virtual void update(const float &frameTime) = 0;

	// Render

	virtual void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr) = 0;

	// Managing scene

	virtual void finalizeScene() = 0;
};

#endif