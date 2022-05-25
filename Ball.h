#pragma once
#include "Types.h"
#include "RectObject.h"
#include <vector>
#include "Brick.h"
#include "Rocket.h"
using namespace std;
class Ball : public RectObject
{
public:
	Ball();
	void Draw() override;
	void HandleWindowReshape() override;
	void Move();
	//void setSpeed(Point speed);
	void SetStartPosition();
	//Point getSpeed() { return speed; };
	Point speed;
private:
	
	//bool CheckCollision(vector<Brick>& bricks, Rect& rocket_pos);
};

