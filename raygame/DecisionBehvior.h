#pragma once
#include "Behavior.h"

class Decision;

class DecisionBehvior :
	public Behavior
{
public:
	DecisionBehvior(Decision* root) { m_root = root; };
	void update(Agent* agent, float deltaTime) override;

private:
	Decision* m_root;
};

