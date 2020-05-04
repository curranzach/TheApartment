#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TextureManager.h"
#include "Button.h"

class StartScreen
{
public:
	sf::Sprite background;
	sf::Sprite title;
	Button newGame;
	Button continue_;
	bool gameStarted = false;
	// Constructors
	StartScreen();
	// Functions
	void Display(sf::RenderWindow& window);
	// Mouse Interactions
	void LeftClick(int posX, int posY);
	void Hover(int posX, int posY);
	bool GameStarted();
};

