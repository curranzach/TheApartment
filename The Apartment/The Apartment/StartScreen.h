#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TextureManager.h"
#include "Button.h"
#include "Player.h"

class StartScreen
{
public:
	int frameCount = 0;
	int spriteChange = 0;
	// Sprites
	sf::Sprite background;
	sf::Sprite title;
	sf::Sprite chooseYourCharacter;
	// Ground
	sf::Sprite* grassTiles[28] = { nullptr };
	sf::Sprite* dirtTiles[28 * 4] = { nullptr };
	// Building
	sf::Sprite* building[7][5];
	sf::Sprite windows[4];
	sf::Sprite doorTop;
	// Buttons
	Button newGame;
	// Bools
	bool newGameClicked = false; // true when player clicks New Game button
	bool enteredBuilding = false; // true when player walks into building
	bool characterSelected = false; // true when player selects character
	bool gameStarted = false; // true when all of the above are true
	bool characterAssigned = false;
	bool curranSelected; bool petermanSelected; bool wyattSelected; bool eganSelected; // true when that character is chosen
	// Character Buttons (for selection)
	Button curran;
	Button peterman;
	Button wyatt;
	Button egan;
	Button selectedCharacter;
	// Constructors
	StartScreen();
	// Functions
	void Display(sf::RenderWindow& window);
	void CreateBuilding();
	void ShowCharacterName(string character, sf::RenderWindow& window);
	bool GameStarted(); // returns true to main when game has started
	// Mouse Interactions
	void LeftClick(int posX, int posY, sf::RenderWindow& window);
	void Hover(int posX, int posY, sf::RenderWindow& window);
};

