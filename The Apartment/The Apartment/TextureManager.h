#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <string>

using std::string;
using std::unordered_map;

class TextureManager {
	static unordered_map<string, sf::Texture> textures;
public:
	static void LoadTexture(const char* fileName);
	static sf::Texture& GetTexture(const char* textureKey);
};


