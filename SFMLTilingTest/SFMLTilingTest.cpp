#include <unordered_map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <string>
#include "TwoDimRenderingEngine.h"
#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char **argv) {
	std::vector<std::string> texture_files{
		"Black", "Red", "Blue", "Green", "Yellow", "Magenta", "Cyan", "White"
	};
	std::unordered_map<std::string, sf::Texture> texture_map;
	std::vector<sf::Texture> sprite_map;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    std::vector<std::vector<unsigned> > tiles{
    	{7,7,7,7,7,0,0,0,0,0,0,7,7,7,7,7},
    	{7,7,7,7,0,1,1,1,1,1,1,0,7,7,7,7},
    	{7,7,7,0,1,7,7,7,7,7,7,1,0,7,7,7},
    	{7,7,0,1,7,0,7,7,7,7,0,7,1,0,7,7},
    	{7,7,0,1,7,1,7,0,0,7,1,7,1,0,7,7},
    	{7,7,0,1,7,7,7,1,1,7,7,7,1,0,7,7},
    	{7,7,0,1,7,0,7,7,7,7,0,7,1,0,7,7},
    	{7,7,7,0,1,7,0,0,0,0,7,1,0,7,7,7},
    	{7,7,7,7,0,1,1,1,1,1,1,0,7,7,7,7},
    	{7,7,7,7,7,0,0,0,0,0,0,7,7,7,7,7},
    };
    unsigned i=0;
    for(std::string texture_file:texture_files){
    	sf::Texture some_texture;
    	sf::Sprite some_sprite;
    	std::string file_name = texture_file + ".png";
    	some_texture.loadFromFile(file_name);
    	texture_map[texture_file]=some_texture;
    	some_sprite.setTexture(texture_map[texture_file]);
    	sprite_map[i++]=some_sprite;
    }

	return 0;
}
