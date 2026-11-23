#include <Game.h>
#include <AssetManager.h>


Game::Game() : 
	mWindow(sf::VideoMode({ SCREEN_W, SCREEN_H }), "Space Aces"), 
	mCamera({static_cast<float>(SCREEN_W), static_cast<float>(SCREEN_H)}, CAM_SCROLL_SPEED),
	mCurrentState(State::MainMenu),
	mMainMenu({ static_cast<float>(SCREEN_W), static_cast<float>(SCREEN_H) })

{
	EnemySpawner::GetInstance().Initialize();
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
	// Get focus for the input to work
	mInputManager.Update(mWindow.hasFocus());

	//Switch between states
	if (mCurrentState == State::MainMenu)
	{
		switch (mMainMenu.Update(mInputManager))
		{
		case MenuAction::Start:
			// Play the actual game
			mCurrentState = State::Game;
			break;
		case MenuAction::Exit:
			// exit the game
			mWindow.close();
			break;
		default:
			break;
		}

		// This ensures the worlds stays frozen for the menu
		return;
	}
	mCamera.Update(deltaTime);
	mScoreUI.SetScore(mScore);
	EnemySpawner::GetInstance().Update(deltaTime, mCamera.GetCameraBoundaries(), Vector(50.0f, 50.0f));
	
}

void Game::Render()
{
	mWindow.clear(sf::Color::Black);

	if (mCurrentState == State::MainMenu)
	{
		Camera::ResetToDefault(mWindow);
		mMainMenu.Draw(mWindow);
	}
	else
	{
		mCamera.ApplyToWorld(mWindow);
		sf::Sprite bgSprite(AssetManager::GetInstance().GetTexture("Assets/Background/bg.png", true));

		sf::FloatRect cameraBoundaries = mCamera.GetCameraBoundaries();

		int top = static_cast<int>(std::floor(cameraBoundaries.position.y)); // get the top

		// Pinning background sprite to top
		bgSprite.setPosition({ cameraBoundaries.position.x, static_cast<float>(top) });

		// and scroll the texture
		bgSprite.setTextureRect({ {0, top}, {SCREEN_W, SCREEN_H} });
		mWindow.draw(bgSprite);
		EnemySpawner::GetInstance().Draw(mWindow);

		Camera::ResetToDefault(mWindow);
		//Render score ui
		mScoreUI.Draw(mWindow);
	}	
	mWindow.display();

}
