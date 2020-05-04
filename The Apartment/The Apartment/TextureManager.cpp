#include "TextureManager.h"

unordered_map<string, sf::Texture> TextureManager::textures;
void TextureManager::LoadTexture(const char* fileName) {
	string filePath = "images/"; // images/
	filePath += fileName; // images/mine
	filePath += ".png"; // images/mine.png

	textures[fileName].loadFromFile(filePath);
}

sf::Texture& TextureManager::GetTexture(const char* textureKey) {
	return textures[textureKey];
}