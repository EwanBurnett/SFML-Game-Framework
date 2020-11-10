#pragma once
#include "../Framework/State_Empty.h"
#include "../Framework/GameMap.h"
#include "../Framework/MapLayer.h"

class State_MainMenu :
    public State_Empty
{
    void Update(sf::Time deltaTime);
    void Render(sf::RenderWindow& window);
    void OnStateEntered();
    void OnStateExit();
    void EventHandler(sf::Event& event);

private:
    //Private variables for this specific game state
    GameMap map;
    MapLayer mLayer;
    MapLayer mLayer2;
    std::vector<MapLayer> Layers;

    sf::Music music;
};