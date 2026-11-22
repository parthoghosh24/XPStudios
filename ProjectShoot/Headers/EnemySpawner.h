#pragma once
#include <Enemy.h>
#include <Config.h>
#include <vector>
#include <random>

class EnemySpawner
{
public:
	
	EnemySpawner(const EnemySpawner&) = delete; // copy constructor not allowed
	EnemySpawner& operator=(const EnemySpawner&) = delete; // No assignment operator allowed

	//Singleton method via which we will access the asset manager
	static EnemySpawner& GetInstance() {
		static EnemySpawner instance;
		return instance;
	}
	void Initialize();
	void Update(float deltaTime, const sf::FloatRect& camBounds, const Vector& playerPos);
	void Draw(sf::RenderWindow& worldWindow);

private:
	// Default constructor is private as it is a singleton
	EnemySpawner() = default;	
	void SpawnEnemy(const sf::FloatRect& camBounds);

	// We will cycle through these states
	enum class State: uint8_t { Spawning, Waiting, Done };

	// This holds all the enemies which we would be spawning
	std::vector<Enemy> mEnemies;

	//current state
	State mCurrentState = State::Done;

	// The timer to calculate spawn breaks
	float mTimer = 0.f;
	int mSpawnedInWave = 0;
	int mSpawnedTotal = 0;

	// For random generation https://en.cppreference.com/cpp/numeric/random/uniform_int_distribution
	std::mt19937 mRange{ std::random_device{}() };
	
};