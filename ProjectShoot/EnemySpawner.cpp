#include "EnemySpawner.h"

void EnemySpawner::Initialize()
{
	// Ensure there are no Enemies added
	mEnemies.clear();

	// We start spawning
	mCurrentState = State::Spawning;

	mTimer = ENEMY_SPAWN_INTERVAL;
}

void EnemySpawner::Update(float deltaTime, const sf::FloatRect& camBounds, const Vector& playerPos)
{
	mTimer += deltaTime;

	// switch between various states for enemy spawnning
	switch (mCurrentState)
	{
	case State::Spawning:
		// Do everything if we are in the spawn interval
		if (mTimer >= ENEMY_SPAWN_INTERVAL)
		{
			// Reduce the enemy spawn interval from timer
			mTimer -= ENEMY_SPAWN_INTERVAL;

			// Spawn enemy within bounds
			SpawnEnemy(camBounds);

			// increment the spawned in wave count
			mSpawnedInWave++;

			// increment total spawned count
			mSpawnedTotal++;

			// We have reached the max
			if (mSpawnedTotal >= TOTAL_ENEMIES)
			{
				// We are done spawning all enemies
				mCurrentState = State::Done;
			}
			else if (mSpawnedInWave >= ENEMIES_PER_WAVE)
			{
				// reset in wave spawn count
				mSpawnedInWave = 0;

				// reset the timer
				mTimer = 0.f;

				//move to waiting state
				mCurrentState = State::Waiting;
			}

		}
		break;

	case State::Waiting:
		// Wait if we are in delay
		if (mTimer >= ENEMY_SPAWN_DELAY)
		{
			// switch to spawn interval
			mTimer = ENEMY_SPAWN_INTERVAL;

			// switch to spawnning again
			mCurrentState = State::Spawning;
		}
		break;

	case State::Done:
		// TODO: We would be most probably call the end game from here
		break;
	}

	// Loop through all enemies and update them
	for (Enemy& enemy : mEnemies)
	{
		enemy.Update(deltaTime, playerPos);
	}

	// Removing enemies once they have gone past the cam bounds - https://stackoverflow.com/questions/39019806/using-erase-remove-if-idiom
	mEnemies.erase(std::remove_if(mEnemies.begin(), mEnemies.end(), [&](const Enemy& enemy) {return enemy.IsBelow(camBounds); }), mEnemies.end());


}

void EnemySpawner::Draw(sf::RenderWindow& worldWindow)
{
	for (Enemy& enemy : mEnemies)
	{
		enemy.Draw(worldWindow);
	}
}

void EnemySpawner::SpawnEnemy(const sf::FloatRect& camBounds)
{
	Enemy& enemy = mEnemies.emplace_back();
	sf::Vector2f enemySize = enemy.GetSize();

	// Computing random float x for enemy  using uniform real distribution
	// The value is generated in a way that x lies between the camera bounds while adjusting for enemy's size. This way
	// we ensure they don't get rendered half clipped or something. 
	std::uniform_real_distribution<float> xDist(camBounds.position.x, camBounds.position.x + camBounds.size.x - enemySize.x);

	enemy.SetPosition(Vector(xDist(mRange), camBounds.position.y - enemySize.y));

}
