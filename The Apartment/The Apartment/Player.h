#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TextureManager.h"
class Player
{
	string characterName;
	sf::Sprite playerSprite;
	//sf::RenderWindow& window;
	int hitPoints;
	// Constructors
	Player(string characterName);
	// Functions
	void Walk();
	void Jump();
};

