//App Class - Ewan Burnett 2021
//A Singleton class which runs the framework application. This handles
//Updating and Drawing frames, and dispatches messages recieved from manager classes
//to the game application. 
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <unordered_set>
#include <vector>
#include <assert.h>


class IGame {
public:
	virtual void Update(float deltaTime) = 0;
};

class App {
public:
	App(IGame* gameInst);
	~App() = default;

	bool Init() const;
	void DoFrame();

	bool Closed() const;

	//Draws the input object onto the relevant layer. 
	static void Draw(int layer, sf::Drawable& object);

	static void Exit();

	//Game Application Methods

	//Start is called when the game begins to run.
	virtual void Start();
	//Update is called once per frame. 
	virtual void Update(float deltaTime);
	//FixedUpdate is called at a constant rate.
	virtual void FixedUpdate(float deltaTime);

private:
	//Singleton for the App class
	static App* m_AppInstance;
	IGame* m_GameInstance;

	sf::RenderWindow m_AppWindow;
	std::vector<std::unordered_set<sf::Drawable*>> m_DrawQueue;

	bool m_bIsClosed;
};
