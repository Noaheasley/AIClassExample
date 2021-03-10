#include "SimpleEnemy.h"
#include "SeekBehavior.h"

bool SimpleEnemy::checkTargetInSight()
{
	//checks if target is null. if so return false
	if (getTarget() == NULL)
		return false;
	//find the direction vector that represent where the target is relative to the enemy
	MathLibrary::Vector2 direction = getTarget()->getWorldPosition() - getWorldPosition();

	//find the dot product of the enemy's forward and direction vector
	MathLibrary::Vector2::dotProduct(getTarget()->getForward(), direction);

	//find the angle using the dot product 
	float angle = (float)MathLibrary::Vector2::findAngle(getTarget()->getForward(), direction);

	//check if that angle is greater than the enemy's  viewing angle(any value you see fit is fine)
	if (angle > 2)
		//returns if the enemy saw something
		return true;
	//returns if the enemy saw nothing
	return false;
}

void SimpleEnemy::onCollision(Actor* other)
{
	//checks to see if the enemy ran into the player

	//if the enemy has run into the player, deal damage to the player

	//if the player's health is less than 0, set target to nullptr
}

void SimpleEnemy::start()
{
	//call base start function
	Enemy::start();

	//set the default state of the enemy
	m_currentState = WANDER;

	//initalize member variables
	m_seekBehavior = getBehaviour<SeekBehavior>();
	m_wanderBehavior = getBehaviour<WanderBehavior>();

	//set the target to be the base class target
	setTarget(Enemy::getTarget());
}

void SimpleEnemy::update(float deltaTime)
{
	//create a switch statement for the state machine
	//the switch should stansition to the wander state if the target is not in sight
	//you can set the wander force to be whatever value you see fit but be sure to set the see force to 0

	//the switch should transition to the seek state if the target is in sight
	//you can set the seek force to be whatever value you see fit, but be sure to set wander force to be 0

	Enemy::update(deltaTime);
}

void SimpleEnemy::setTarget(Agent* target)
{
	Enemy::setTarget(target);
	m_seekBehavior->setTarget(target);
}
