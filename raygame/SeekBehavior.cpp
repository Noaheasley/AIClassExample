#include "SeekBehavior.h"
#include "Agent.h"

SeekBehavior::SeekBehavior()
{
	m_target = nullptr;
	m_seekForce = 1;
}

SeekBehavior::SeekBehavior(Actor* target, float seekForce)
{
	m_target = target;
	m_seekForce = seekForce;
}

MathLibrary::Vector2 SeekBehavior::calculateForce(Agent* agent)
{
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(m_target->getWorldPosition() - agent->getWorldPosition());

	MathLibrary::Vector2 desiredVelocity = direction * m_seekForce;

	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();
	return MathLibrary::Vector2();
}

void SeekBehavior::update(Agent* agent, float deltaTime)
{
	if (agent)
		agent->addForce(calculateForce(agent));
}
