#include "DecisionBehvior.h"
#include "Decision.h"

void DecisionBehvior::update(Agent* agent, float deltaTime)
{
	if (agent)
		m_root->makeDecision(agent, deltaTime);
}
