#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy(float x, float y, float collisionRadius, const char* spriteFilePath, Agent* target, float health, float damage, float maxSpeed = 1, float maxForce = 1);
	void update(float deltaTime) override;
	virtual Actor* getTarget() { return m_target; }
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target;
};

