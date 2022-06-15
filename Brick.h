#pragma once
#include "RectObject.h"
#include "Types.h"

class Brick : public RectObject
{
public:
	Brick(int strength, int row, int col);
	void HandleWindowReshape() override {};
	void Draw() override;
	bool Hit();
	int getCol() { return col; };
	int getRow() { return row; };
	int GetStrength() { return strength; };
	static int col_number;
private:
	int strength;
	Bonus bonus;
	int col;
	int row;
};



