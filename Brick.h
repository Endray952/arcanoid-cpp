#pragma once
#include "RectObject.h"
#include "Types.h"

class Brick : private RectObject
{
public:
	Brick(Bonus bonus, Rect position, int strength);
	void Draw() {};
	void Hit(int& bricks_left);
private:
	int strength;
	Bonus bonus;
};



