#include "Button.h"

void Button::SetImage(const char* filename) {
	this->filename = filename;
	button.setTexture(TextureManager::GetTexture(filename));
}

void Button::Display(sf::RenderWindow& window) {
	window.draw(button);
}

void Button::SetPosition(int xPos, int yPos) {
	button.setPosition(xPos, yPos);
}

sf::Sprite& Button::GetSprite() {
	return button;
}

void Button::Illuminate() {
	string newFilename = filename + "I";
	const char* c = newFilename.c_str();
	button.setTexture(TextureManager::GetTexture(c));
}