#pragma once

#include "enemy.h"

class BasicEnemy : public Enemy
{
public:
	BasicEnemy(int ntype, double nx, double ny, double nvx, double nvy);
	~BasicEnemy(){};

	void Logic();
protected:
private:
};