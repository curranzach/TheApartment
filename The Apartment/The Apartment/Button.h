#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TextureManager.h"
class Button
{
public:
	sf::Sprite buttonSprite;
	string filename;
	bool illuminated = false;
	bool locked = false;
	// Functions
	void Display(sf::RenderWindow& window); // Displays button on window/updates with interaction
	void SetImage(const char* filename);
	void SetPosition(int xPos, int yPos);
	void Illuminate();
	void Deluminate();
	sf::Sprite& GetSprite();
	// Copy Assignment Operator
	Button& operator=(Button& rhs);
};

