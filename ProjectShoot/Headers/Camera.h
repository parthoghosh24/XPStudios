#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera(sf::Vector2f cameraSize, float cameraScrollSpeed);

	// We would move the camera upwards so the world moves downwards. For that, our x would be 0 and y would be negative (SFML's 0,0
	// starts top left of screen). We have to multiply the y with cameraScrollSpeed to get scroll effect. Ofcourse detlatime needs to be multiplied
	// to stay consistent with FPS.
	void Update(float deltaTime);

	// Apply the camera to world.
	void ApplyToWorld(sf::RenderWindow& worldWindow) const;

	//This is required for HUD screen like healthbar, ammo, timer, etc. Screen coordinates need to be reset to 0, 0 for fixed perspective.
	static void ResetToDefault(sf::RenderWindow& worldWindow);

	// We are getting the camera bounding box here. In other words, we get the dimensions of camera as a rectangle in which we could see things.

	sf::FloatRect GetCameraBoundaries() const;


private:
	sf::View mCameraView;
	float mCameraScrollSpeed;
};