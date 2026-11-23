#pragma once

#include <SFML/Graphics.hpp>
#include <Camera.h>
#include <Config.h>
#include <EnemySpawner.h>
#include <iostream>
#include <InputManager.h>
#include <MainMenu.h>
#include <ScoreUI.h>

/*
* Game.h - This is the core class of the game which will handle various
* use cases like user input, rendering, game loop and frame rate.
*/

class Game
{
public: 
	Game();
	void Run();

private:
	sf::RenderWindow mWindow; // Window to be rendered	
	Camera mCamera;	
	ScoreUI mScoreUI;
	int mScore = 0;

	void HandleEvents();
	void Update(float deltaTime); // Similar to Unity, we could handle the update logic in this
	void Render();

	enum class State : uint8_t
	{
		MainMenu,
		Game
	};

	State mCurrentState = State::MainMenu;
	InputManager mInputManager;
	MainMenu mMainMenu;

};
