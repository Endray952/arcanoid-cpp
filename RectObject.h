#pragma once
#include "Types.h"
class RectObject
{
public:
	//RectObject(Rect initial_position): position(initial_position) {};
	virtual void Draw() = 0;
	Rect GetPosition() { return position; };
	//void SetPosition();
protected:
	Rect position;
	float width;
	float height;
	Point pos;
};

