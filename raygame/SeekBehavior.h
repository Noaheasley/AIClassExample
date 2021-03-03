#pragma once
#include "SteeringBehavior.h"

class Actor;

class SeekBehavior : public SteeringBehavior
{
public:
	SeekBehavior();
	SeekBehavior(Actor* target, float seekForce = 1);

	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	void update(Agent* agent, float deltaTime) override;
private:
	Actor* m_target;
	float m_seekForce;
};

