#pragma once

#include <SFML/Graphics.hpp>
#include <Config.h>
#include <iostream>

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

	void HandleEvents();
	void Update(float deltaTime); // Similar to Unity, we could handle the update logic in this
	void Render();

};
