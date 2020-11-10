#include "State_MainMenu.h"
#include<assert.h>

void State_MainMenu::Update(sf::Time deltaTime)
{
}

void State_MainMenu::Render(sf::RenderWindow& window)
{
	window.setTitle("Main Menu");

	//map.ConstructMap(Layers, 6, 3, 16);
	
	map.RenderMap(window);

	//Example
	//sf::sleep(sf::seconds(3));
	//Game::TryPop(); //Removing the state from the stack
}

void State_MainMenu::OnStateEntered()
{
	//map.ConstructMap(map.LoadFromFile("Debug/testMap.csv", ResourceManager::GetTexture("FFV_1.png")), 30, 20, 16);

	//music.openFromFile("Debug/BGM.ogg");
	music.setLoop(true);
	music.play();
}

void State_MainMenu::OnStateExit()
{
}

void State_MainMenu::EventHandler(sf::Event& event)
{
}
