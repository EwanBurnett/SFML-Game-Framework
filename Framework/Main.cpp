#include "App.h"
#include <iostream>

int main() {
    Game game;
    App app(&game);
    
}
void Game::Update(float deltaTime) {
    
        sf::CircleShape shape(200.0f);
        shape.setFillColor(sf::Color::Blue);
        App::Draw(0, shape);

        std::cout << "Updating Game" << std::endl;
}

