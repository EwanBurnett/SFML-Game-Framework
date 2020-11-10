#include "GameMap.h"

#include<iostream>

GameMap::GameMap()
{
}

void GameMap::ConstructMap(std::vector<MapLayer> l_Layers, int l_MapWidth, int l_MapHeight, int l_TileSize)
{
	//Initialises map values
	m_Layers = l_Layers;
	m_MapHeight = l_MapHeight;
	m_MapWidth = l_MapWidth;
	m_TileSize = l_TileSize;
}

sf::Vector2i GameMap::GetTilemapTile(int index, int tileMapWidth)
{
	int x = ((index + tileMapWidth) % tileMapWidth) - 1;
	int y = (index / (tileMapWidth));

	return sf::Vector2i(x, y);
}

void GameMap::RenderMap(sf::RenderWindow& window)
{
	//For each Layer in Layers...
	for (MapLayer Layer : m_Layers) {

		if (Layer.LayerData.size() != m_MapHeight * m_MapWidth) {
			Layer.LayerData.resize(m_MapWidth * m_MapHeight);
		}

		//Loops over each value in the layer...
		for (int y = 0; y < m_MapHeight; ++y) {

			for (int x = 0; x < m_MapWidth; ++x) {
				//std::cout << "COORD - (" << x << ", " << y << ") - " << std::endl;

				int TileMapWidth = Layer.TileMap.getSize().x / m_TileSize; //Divides tilemap x by tilesize to get tilemap width

				int index = x + m_MapWidth * y; //Calculates index
				int val = Layer.LayerData.at(index); //The data in the layer at index
				
				//Only draw if the value is greater than 0
				if (val > 0) {

					//Gets a slice from the TileMap
					sf::Vector2i TileSlice = GetTilemapTile(val, TileMapWidth);
					TileSlice.x += Layer.TileMapOffset.x;
					TileSlice.y += Layer.TileMapOffset.y;

					sf::Sprite Tile(Layer.TileMap);

					Tile.setTextureRect(sf::IntRect(TileSlice.x * m_TileSize, TileSlice.y * m_TileSize, m_TileSize, m_TileSize));

					Tile.setPosition(static_cast<float>(x * m_TileSize) , static_cast<float>(y * m_TileSize));

					//sf::IntRect debugRect = Tile.getTextureRect();

					//std::cout << "	TILE " << val << " (" << Tile.getTextureRect().left << ", " << Tile.getTextureRect().top << ") RETURNED." << std::endl;
					//std::cout << "	TILE DRAWN AT (" << Tile.getPosition().x << ", " << Tile.getPosition().y << "). " << std::endl;

					//Draws the tile to the window
					window.draw(Tile);
				}
				
			}
			
		}
	}
}

//TODO - Refactor & optimize, add layer support, properly comment. Consider upgrading to use XML or a TMX parser, so I can do less work
std::vector<MapLayer> GameMap::LoadFromFile(std::string FileName, sf::Texture TileMap)
{
	std::ifstream mapFile;
	mapFile.open(FileName);

	std::vector<MapLayer> lLayers;
	std::vector<int> lLayer;

	MapLayer layerCache;

	sf::Time elapsed;
	sf::Clock clock;

	std::cout << "Loading " << FileName << "..." << std::endl;

	int maplayers = 0;
	std::vector<std::string> lLayerCache;

	//Copy data from the file to the lLayerCache vector..
	while (mapFile.good()) {
		std::string line;
		std::getline(mapFile, line, '/');
		maplayers++;
		
		lLayerCache.push_back(line);
	}
	mapFile.close(); //Make sure to close the file when it's not needed.

	//For each layer...
	for (int i = 0; i < maplayers; ++i) {
		std::string currentLayer = lLayerCache.at(i);
		
		//Parse string, using ',' as delimiter.
		std::string delimiter = ",";
		size_t pos = 0;
		int token;
		while ((pos = currentLayer.find(delimiter)) != std::string::npos) {
			token = std::stoi(currentLayer.substr(0, pos));
			lLayer.push_back(token); //Add the data to the lLayer vector...
			currentLayer.erase(0, pos + delimiter.length());
		}

		//Create a new MapLayer from the current layer data
		layerCache.ConstructLayer(lLayer, sf::Vector2i(0, 0), TileMap);

		//Add that to the layers vector
		lLayers.push_back(layerCache);
		lLayer.clear(); //Clear the layer cache
	}

	elapsed = clock.restart();
	std::cout << "Map " << FileName << " finished loading in " << elapsed.asMilliseconds() << "ms.\n " << maplayers << " layers drawn.\n" << std::endl;
	

	return(lLayers);
}
