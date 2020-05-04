#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TextureManager.h"
class Button
{
public:
	sf::Sprite button;
	string filename;
	// Functions
	void Display(sf::RenderWindow& window); // Displays button on window/updates with interaction
	void SetImage(const char* filename);
	void SetPosition(int xPos, int yPos);
	void Illuminate();
	sf::Sprite& GetSprite();
};

