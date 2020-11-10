#pragma once
#include "ResourceManager.h"
#include "MapLayer.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>


class GameMap {
public:
	GameMap();
	void ConstructMap(std::vector<MapLayer> l_Layers, int l_MapWidth, int l_MapHeight, int l_TileSize);
	sf::Vector2i GetTilemapTile(int index, int tileMapWidth);
	void RenderMap(sf::RenderWindow& window);

	std::vector<MapLayer> LoadFromFile(std::string FileName, sf::Texture TileMap);

private:
	std::vector<MapLayer> m_Layers; //The individual layers within the tilemap. Drawn from back to front.

	uint16_t m_TileSize = 16; //How big each tile is. 16 = 16 x 16 tiles etc.
	int m_MapWidth = 1; //The width of the map (in tiles).
	int m_MapHeight = 1; //The height of the map (in tiles).
};