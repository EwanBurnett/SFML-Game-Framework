#include "App.h"
#include "Utils/tinyxml2.h"
#include <Windows.h>
#include <iostream>

int main() {
    //Set up Memory Leak Flags
    int tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    //Always perform a memory leak check before the application exits
    tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(tmpDbgFlag);

    //Init Game Logger
    

    //Instantiate the Game and Application
    Game game;
    App app(&game);

    std::cout << "Game Exited" << std::endl;
    return 'sfml';
}


void Game::Update(float deltaTime) {
    
    //Debug Code
    sf::CircleShape shape(200.0f);
    shape.setFillColor(sf::Color::Blue);
    App::Draw(0, shape);
    RNG rng;

    std::cout << rng.RandInt(100) << std::endl;

}

