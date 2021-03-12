#pragma once
#include "Enemy.h"

enum EnemyState
{
	WANDER,
	SEEK
};

class WanderBehavior;
class SeekBehavior;

class SimpleEnemy :
	public Enemy
{
	using Enemy::Enemy;
	bool checkTargetInSight();

	void onCollision(Character* other);
	void start() override;
	void update(float deltaTime) override;

	void setTarget(Agent* target);
private:
	EnemyState m_currentState;
	WanderBehavior* m_wanderBehavior;
	SeekBehavior* m_seekBehavior;
};

