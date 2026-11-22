#pragma once
#include <IHitable.h>
#include <SFML/Graphics.hpp>
#include <Config.h>
#include <Vector.h>


#define ENGINE_FRAME_SIZE 128
#define ENGINE_FRAMES 12 //1536px / 128
#define ENGINE_FRAME_TIME 0.06f
#define SINE_AMPLITUDE 150.f
#define SINE_FREQUENCY 2.f

class Enemy: public Ihitable
{
public:
	Enemy();
	~Enemy() = default;

	// We want to update the enemy's position. We need the player position so that we could shoot them
	void Update(float deltaTime, Vector playerPos);
	void Draw(sf::RenderWindow& worldWindow);
	void TakeDamage(int damage) override;

	// This returns the sprite size so we could calculate collision, bounds and stuff
	sf::Vector2f GetSize() const;

	// This will help is set position from outside Enemy class (specifically from EnemySpawner)
	void SetPosition(const Vector& pos);	

	// This method helps determing whether this enemy is has gone past the camera's Y bounds
	bool IsBelow(const sf::FloatRect& cam) const;

private:
	enum class Pattern : uint8_t
	{
		Straight = 0,
		Sine = 1
	};

	sf::Sprite mEnemySprite;
	sf::Sprite mEnemyEngineSprite;
	int mEngineFrame = 0; // This holds the index for the engine frame image
	int mHealth;
	float mEnemySpeed;
	float mEnemyEngineTimer;
	Vector mPosition;
	Pattern mCurrentPattern = Pattern::Straight;
	// For random generation https://en.cppreference.com/cpp/numeric/random/uniform_int_distribution	
	void SyncSprites();
	float mBaseX = 0.f;
	float mElapsed = 0.f;

	

	
};
