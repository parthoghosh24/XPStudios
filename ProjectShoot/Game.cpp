#include <Game.h>



Game::Game() : mWindow(sf::VideoMode({ SCREEN_W, SCREEN_H }), "Project shooter")
{
	// Default constructor
}

void Game::Run()
{
	// Setting the fps - default is 60.
	mWindow.setFramerateLimit(FPS);

	// This is required to calculate the deltaTime similar to Unity
	sf::Clock deltaClock;

	// Run the windowing logic and game loop from SFML here
	while (mWindow.isOpen())
	{		
		float deltaTime = deltaClock.restart().asSeconds();
		HandleEvents();
		Update(deltaTime);
		
		Render();
	}
}

void Game::HandleEvents()
{
	while (const std::optional event = mWindow.pollEvent())
	{
		//TODO: some events like keyboard press and all
		if (event->is<sf::Event::Closed>())
		{
			// Close windows
			mWindow.close();			
		}
	}

}

void Game::Update(float deltaTime)
{
	//TODO: We will perform Unity like updates here
}

void Game::Render()
{
	mWindow.clear();

	//TODO: We will display things here
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	mWindow.draw(shape);
	mWindow.display();

}
