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
	void setSpeedX(float speedX) { speed.x = speedX; };
	void setSpeedY(float speedY) { speed.y = speedY; };
	void inverseSpeedX() { speed.x = -speed.x; };
	void inverseSpeedY() { speed.y = -speed.y; };
	void SetStartPosition();
	Point getSpeed() { return speed; };
	
private:
	Point speed;
};

