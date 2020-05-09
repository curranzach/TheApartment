#pragma once
#include <SFML/Graphics.hpp>
#include <zLib\zlib.h>
#include <tmx/MapLoader.hpp>
#include <iostream>
#include <string>
#include "TextureManager.h"
class Player
{
public:
	sf::Vector2f hitBox[4]; //Array containing the 4 corners of the player sprite
	std::vector<tmx::MapLayer> layers;
	// Add each of these points to the sprites current position
	sf::Vector2f currentPosition;
	int walkingCounter;
	string playerName;
	sf::Sprite playerSprite;
	int hitPoints;
	int movementSpeed = 10;
	bool facingRight = true;
	bool moving = false;
	// Constructors
	Player();
	// Functions
	void Create(string playerName);
	void Display(sf::RenderWindow& window);
	void SetSprite();
	sf::Sprite& GetSprite();
	void Walk(char direction);
	void Animate(char direction);
	void CheckCollision();
	void Jump();
	void SetMap(std::vector<tmx::MapLayer>& layers);
};

