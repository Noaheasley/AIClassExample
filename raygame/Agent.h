#pragma once
#include <vector>
#include "Actor.h"

class Behavior;

class Agent : public Actor
{
public:
	Agent();
    ~Agent();
    /// <param name="x">Position on the x axis</param>
/// <param name="y">Position on the y axis</param>
/// <param name="icon">The symbol that will appear when drawn</param>
    Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce);

    float getMaxForce() { return m_maxForce; }
    void setMaxForce(float maxForce) { m_maxForce = maxForce; }

    void addForce(MathLibrary::Vector2 force);
    void update(float deltaTime);
    void addBehavior(Behavior* behavior);
private:
	MathLibrary::Vector2 m_force;
	float m_maxForce;
	std::vector<Behavior*> m_behaviors;
};

