#include "App.h"

App* App::m_AppInstance = nullptr;

App::App(IGame* gameInst)
{
	//Singleton setup
	assert(m_AppInstance == nullptr);
	m_AppInstance = this;

	m_GameInstance = gameInst;

	//Set up the App Window
	m_AppWindow.create(sf::VideoMode(1280, 720), "Game Window");

	m_AppWindow.setFramerateLimit(60);
	m_AppWindow.setVerticalSyncEnabled(false);

	//Initialize the application
	assert(Init());

	//Start Frame Processing
	DoFrame();
}

bool App::Init() const
{
	//Init Draw Queue
	m_AppInstance->m_DrawQueue.resize(3);

	//Start Time

	//Seed RNG

	//Init Managers

	//Pre-Allocate Memory

	//Init Box2D World

	return true;
}

void App::DoFrame()
{
	while (m_AppWindow.isOpen()) {
		//Calculate App Timing

		//Process and forward input events
		sf::Event event;
		while (m_AppWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_AppWindow.close();
		}

		//Update the application
		Update(0);
		FixedUpdate(0);

		//Draw to the screen
		for (auto& layer : m_DrawQueue) {
			for (auto& item : layer) {
				//m_AppWindow.draw(*item);
				//TODO: Draw custom Drawable / transfomable class instead of sf::Drawable
			}
		}

		//Present the swapchain
		m_AppWindow.clear();
		m_AppWindow.display();
	}
	
	
}

bool App::Closed() const
{
	return m_AppInstance->m_bIsClosed;
}

void App::Draw(int layer, sf::Drawable& object)
{

	m_AppInstance->m_DrawQueue.at(layer).emplace(&object);
	
}

void App::Exit()
{
	m_AppInstance->m_AppWindow.close();
	m_AppInstance->m_bIsClosed = true;
}

void App::Start()
{
}

void App::Update(float deltaTime)
{
	m_AppInstance->m_GameInstance->Update(deltaTime);
}

void App::FixedUpdate(float deltaTime)
{
}
