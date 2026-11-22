#include <Camera.h>

Camera::Camera(sf::Vector2f cameraSize, float cameraScrollSpeed): 
	mCameraView(cameraSize * 0.5f, cameraSize), mCameraScrollSpeed(cameraScrollSpeed) // halfing the size to set center of the camera
{
	// Initializing camera
}

void Camera::Update(float deltaTime)
{
	mCameraView.move({ 0.0f, -mCameraScrollSpeed * deltaTime }); 
}

void Camera::ApplyToWorld(sf::RenderWindow& worldWindow) const
{
	worldWindow.setView(mCameraView);
}

void Camera::ResetToDefault(sf::RenderWindow& worldWindow)
{
	worldWindow.setView(worldWindow.getDefaultView());
}

sf::FloatRect Camera::GetCameraBoundaries() const
{
	sf::Vector2f cameraSize = mCameraView.getSize(); // Get the camera size

	// return the area between topLeft of cameraView and bottomRight (which is cameraSize)
	// Something like below
	/*
	--------------------
	|(0,0)				|
	|					|
	|					|	
	|		(1920, 1080)|
	|-------------------|
	
	
	*/
	return {mCameraView.getCenter() - cameraSize/2.f, cameraSize}; 
}
