#include "Player.h"
Player::Player(string characterName) {
	this->characterName = characterName;
	// Set sprite
	if (characterName == "curran")
		playerSprite.setTexture(TextureManager::GetTexture("curran_front"));
}