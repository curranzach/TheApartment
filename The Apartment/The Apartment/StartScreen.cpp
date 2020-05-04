#include "StartScreen.h"

StartScreen::StartScreen() {
	// Set texture on bg and title sprites
	background.setTexture(TextureManager::GetTexture("backgroundImage"));
	title.setTexture(TextureManager::GetTexture("title"));
	// Set texture on newGame and continue buttons
	newGame.SetImage("newGame");
	continue_.SetImage("continue");
	// Set position of sprites and buttons 
	title.setPosition(450, 30);
	newGame.SetPosition(700, 350);
	continue_.SetPosition(700, 600);
}

void StartScreen::Display(sf::RenderWindow& window) {
	// Draw bg and title to window
	window.draw(background);
	window.draw(title);
	// Update newGame and continue buttons
	newGame.Display(window);
	continue_.Display(window);

}

void StartScreen::LeftClick(int xPos, int yPos) {
	// If player clicks on New Game button
	if (newGame.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) { // If button's sprite is in pos of click
		gameStarted = true;
	}
}

void StartScreen::Hover(int xPos, int yPos) {
	if (newGame.GetSprite().getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		newGame.Illuminate();
}
}

bool StartScreen::GameStarted() {
	return gameStarted;
}