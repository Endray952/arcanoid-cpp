#pragma once
#include "Types.h"
#include "RectObject.h"
#include <vector>
#include "Brick.h"
using namespace std;
class Ball : private RectObject
{
public:
	Ball(float radius, Point speed);
	void Draw() {};
	bool Move();
	void setSpeed(Point speed);
private:
	Point speed;
	float radius;

	bool CheckCollision(vector<Brick>& bricks, Rect& rocket_pos);
};

