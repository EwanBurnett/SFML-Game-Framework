#include "App.h"

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

	m_FixedInterval = 1.0f / 60.0f;	//60fps fixed timestep

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
	
	//Start the Game 
	Start();

	return true; 
}

void App::DoFrame()
{
	while (m_AppWindow.isOpen()) {

		//Calculate App Timing
		m_Time.Tick();
		float dt = m_Time.DeltaTime();
		
		static float accumulator = 0;
		accumulator += dt;

		//Process and forward input events
		sf::Event event;
		while (m_AppWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_AppWindow.close();
		}

		//Update the application
		Update(dt);
		while (accumulator >= m_FixedInterval) {
			FixedUpdate((float)m_FixedInterval);
			accumulator -= m_FixedInterval;
		}
		

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
	m_GameInstance->Start();
}

void App::Update(float deltaTime)
{
	m_GameInstance->Update(deltaTime);
}

void App::FixedUpdate(float deltaTime)
{
	m_GameInstance->FixedUpdate(deltaTime);
}
