#pragma once
#include "RectObject.h"
#include "Types.h"

class Brick : public RectObject
{
public:
	Brick(Point position, int strength, int row, int col);
	void HandleWindowReshape() {};
	void Draw() override;
	void Hit();
	int col;
	int row;
	int GetStrength() { return strength; };
private:
	int strength;
	Bonus bonus;
};



