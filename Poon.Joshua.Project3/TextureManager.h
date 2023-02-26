#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;
using namespace sf;

class TextureManager
{
	static unordered_map<string, Texture> textures;
	static void loadTexture(string textureName);
public:
	
	static Texture& getTexture(string textureName);
	static void Clear();

};

