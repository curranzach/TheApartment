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
	// Collision
	sf::Vector2f hitBox[4]; //Array containing the 4 sides of the player sprite
	std::vector<tmx::MapLayer> layers;
	sf::Vector2f currentPosition;
	string playerName;
	sf::Sprite playerSprite;
	int hitPoints;
	// Movement
	int walkingCounter;
	int movementSpeedRight = 10;
	int movementSpeedLeft = 10;
	bool facingRight = false;
	bool moving = false;
	// Air movement
	int gravitySpeed = 6;
	bool falling = false;
	bool CheckIfFalling();
	// Constructors
	Player();
	// Functions
	void Create(string playerName);
	void Display(sf::RenderWindow& window);
	void SetSprite();
	sf::Sprite& GetSprite();
	void Walk(char direction);
	void Fall();
	void Animate(char direction);
	void CheckCollision();
	void Jump();
	void SetMap(std::vector<tmx::MapLayer>& layers);
};

