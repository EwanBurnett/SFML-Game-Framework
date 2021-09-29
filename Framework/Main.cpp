#include "App.h"
#include <iostream>

class Game : public IGame {

    void Update(float deltaTime) override {
        sf::CircleShape shape(200.0f);
        shape.setFillColor(sf::Color::Blue);
        App::Draw(0, shape);

        std::cout << "Updating Game" << std::endl;
    }
};

int main() {
    Game game;
    App app(&game);
    
}

