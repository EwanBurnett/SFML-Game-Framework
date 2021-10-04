#include "App.h"
#include <iostream> //DEBUG

App* App::m_AppInstance = nullptr;

App::App(IGame* gameInst)
{
	//Singleton setup
	assert(m_AppInstance == nullptr);
	m_AppInstance = this;

	m_GameInstance = gameInst;
	
	//Initialize the application
	assert(Init());

	//Start Frame Processing
	DoFrame();
}

bool App::Init()
{
	//Start Time
	m_Time.Reset();
	m_Time.SetTimeScale(1.0f);

	//Seed RNG
	m_RNG.Seed(m_Time.BaseTime());

	//Pre-Allocate Memory
	
	//Set up the App Window
	m_AppWindow.setFramerateLimit(60);
	m_AppWindow.setVerticalSyncEnabled(false);

	//Init Managers

	//Pre-load resources

	//Load Config	

	//Create the App Window
	m_AppWindow.create(sf::VideoMode(1280, 720), "Game Window");

	//Init Draw Queue
	m_AppInstance->m_DrawQueue.resize(3);

	

	//Init Physics
	/*b2Vec2 gravity(0.0f, -9.8);
	b2World world(gravity);*/
	
	
	return true; 
}

void App::DoFrame()
{
	while (m_AppWindow.isOpen()) {
		//Calculate App Timing

		/*m_DeltaTime = m_Clock.restart();	//Using SFML Clock
		m_AppTime += m_DeltaTime;
		float dt = m_DeltaTime.asSeconds();*/
		
		m_Time.Tick();
		float dt = m_Time.DeltaTime();
		std::cout << m_Time.TotalTime() << std::endl;

		//Process and forward input events
		sf::Event event;
		while (m_AppWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_AppWindow.close();
		}

		//Update the application
		Update(dt);
		FixedUpdate(dt);

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

void App::OnExit()
{
	//Deallocate systems in reverse order

	//Managers
	//Game Window
	m_AppWindow.close();
	//Resource Cache
	//RNG
	//Time
}

void App::Start()
{
}

void App::Update(float deltaTime)
{
	m_GameInstance->Update(deltaTime);
}

void App::FixedUpdate(float deltaTime)
{
	//m_GameInstance->FixedUpdate(deltaTime);
}
