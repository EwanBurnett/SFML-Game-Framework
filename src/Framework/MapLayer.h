#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct MapLayer {
	
	void ConstructLayer(std::vector<int> l_LayerData, sf::Vector2i l_TileMapOffset, sf::Texture l_TileMap) {
		TileMapOffset = l_TileMapOffset;
		TileMap = l_TileMap;
		LayerData = l_LayerData;
	}

	sf::Vector2i TileMapOffset;
	sf::Texture TileMap;
	std::vector<int> LayerData;

};
