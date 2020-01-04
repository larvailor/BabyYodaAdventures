#ifndef SCENE_HPP
#define SCENE_HPP

#include "Entity.hpp"
#include "Button.hpp"

class Scene
{
protected:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Render targets
	//

	/* A shared_ptr to a window on which the scene is drawn */
	std::shared_ptr<sf::RenderWindow> m_renderWindow;

	//-----------------------------------------------
	//		Keys
	//

	/* A map of keys that are used by the scene */
	std::map<std::string, sf::Keyboard::Key> m_keyBinds;

	//-----------------------------------------------
	//		Mouse positions
	//

	/* Mouse position on the native screen */
	sf::Vector2i m_mousePosScreen;

	/* Mouse position inside the window */
	sf::Vector2i m_mousePosWindow;

	/* Mouse position on the view (example: a big tile map) */
	sf::Vector2f m_mousePosView;

	//-----------------------------------------------
	//		Scene state
	//

	/* Indicates should the scene be completed or not */
	bool m_close;

	//-----------------------------------------------
	//		Resources
	//
	
		// Textures
	
	/**
		A vector of textures that are used by the scene 
		TODO: make a map of textures
	*/
	std::vector<std::shared_ptr<sf::Texture>> m_textures;
	
		// Fonts

	/**
		A font that is used by the scene.
		TODO: make a map of fonts
	*/
	std::shared_ptr<sf::Font> m_font;

		// Buttons

	/* A map of buttons that are used by the scene*/
	std::map<std::string, std::shared_ptr<Button>> m_buttons;



	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	/**
		Loads all key binds for specific scene
		and creates an std::map of supported keys and their codes
	*/
	virtual void initKeyBinds(std::string pathToKeyBinsIni, const std::map<std::string, sf::Keyboard::Key> *const supportedKeys);

	virtual void initFont(std::string pathToFont);

	/**
		Loads all buttons that are used by the scene.
		Should be called after fonts were initialized
	*/
	virtual void initButtons(std::string pathToButtonsIni);

	//-----------------------------------------------
	//		Update
	//

	virtual void handleInput(const float &frameTime) = 0;
	virtual void updateMousePositions();

	//-----------------------------------------------
	//		Managing scene
	//

	virtual void checkForClose();

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Scene(std::shared_ptr<sf::RenderWindow> &renderWindow, const std::map<std::string, sf::Keyboard::Key> *const supportedKeys);

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Scene();

	//-----------------------------------------------
	//		Accessors
	//

		// Getters

	bool needToBeClosed() const;

	//-----------------------------------------------
	//		Update
	//

	virtual void update(const float &frameTime) = 0;

	//-----------------------------------------------
	//		Render
	//

	virtual void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr) = 0;

	//-----------------------------------------------
	//		Managing state
	//

	virtual void finalizeScene() = 0;
};

#endif
