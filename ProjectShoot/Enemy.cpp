#include <Enemy.h>
#include <AssetManager.h>
#include <cmath>
#include <random>

static std::mt19937 mRange{ std::random_device{}() }; // We don't need this to be created per instance

Enemy::Enemy(): mEnemySprite(AssetManager::GetInstance().GetTexture("Assets/Enemy/enemy.png", false)),
				mEnemyEngineSprite(AssetManager::GetInstance().GetTexture("Assets/Enemy/enemyEngine.png", false)),
				mPosition(Vector(0.0f, 0.0f)),
				mHealth(1),
				mEnemySpeed(ENEMY_MOVE_SPEED),
				mEnemyEngineTimer(0.f)
{
	// Randomly choose between patterns
	std::uniform_int_distribution<int> dist(0, 1);
	mCurrentPattern = static_cast<Pattern>(dist(mRange));
	SetPosition(mPosition);

	//initalize with the first frame of the engine sprite
	mEnemyEngineSprite.setTextureRect({ { 0, 0 }, { ENGINE_FRAME_SIZE, ENGINE_FRAME_SIZE } });

	// The ship and its engine thrusters needs to be flipped to down as it is facing upward in the actual PNG
	for (sf::Sprite* sprite: {&mEnemySprite, &mEnemyEngineSprite})
	{
		// Find and set the origin to center
		sprite->setOrigin({ ENGINE_FRAME_SIZE / 2.f, ENGINE_FRAME_SIZE / 2.f });

		// Rotate 180 deg to make it point down.
		sprite->setRotation(sf::degrees(180.f));

		// Set position using ship's position
		sprite->setPosition({ mPosition.mX, mPosition.mY });
	}

	
}

void Enemy::Update(float deltaTime, Vector playerPos)
{
	mElapsed += deltaTime;
	mPosition.mY += deltaTime * mEnemySpeed;
	

	if (mCurrentPattern == Pattern::Sine)
	{
		// x = baseX + ampl * sin(mElapsed * freq)
		mPosition.mX = mBaseX + SINE_AMPLITUDE * std::sin(mElapsed * SINE_FREQUENCY);
	}
	else
	{
		// Straight line
		mPosition.mX = mBaseX;
	}

	SyncSprites();
	// Perform thruster flashing.
	// We have to cycle through all the images in the enemy engine sprite for this effect.

	mEnemyEngineTimer += deltaTime;

	if (mEnemyEngineTimer >= ENGINE_FRAME_TIME)
	{
		mEnemyEngineTimer -= ENGINE_FRAME_TIME;
		mEngineFrame = (mEngineFrame + 1) % ENGINE_FRAMES; // rotate through each frame in the image
		mEnemyEngineSprite.setTextureRect({ { mEngineFrame * ENGINE_FRAME_SIZE, 0 }, {ENGINE_FRAME_SIZE, ENGINE_FRAME_SIZE} });
	}
	
	//TODO: use playerPos to shoot at it
}

void Enemy::Draw(sf::RenderWindow& worldWindow)
{
	// draw in this order
	// engine sprite
	// actual ship
	worldWindow.draw(mEnemyEngineSprite);
	worldWindow.draw(mEnemySprite);
	
}

void Enemy::TakeDamage(int damage)
{
	// TODO: Taking damage
}

sf::Vector2f Enemy::GetSize() const
{
	return mEnemySprite.getGlobalBounds().size;
}

void Enemy::SetPosition(const Vector& pos)
{
	mPosition = pos;
	mBaseX = pos.mX;
	SyncSprites();
}

bool Enemy::IsBelow(const sf::FloatRect& cam) const
{
	return mPosition.mY > cam.position.y + cam.size.y;
}

void Enemy::SyncSprites()
{
	mEnemyEngineSprite.setPosition({ mPosition.mX, mPosition.mY });
	mEnemySprite.setPosition({ mPosition.mX, mPosition.mY });
}


