#pragma once
#include "Types.h"
class RectObject
{
public:
	virtual void Draw() = 0;
	virtual void HandleWindowReshape() = 0;
	float getWidth() { return width; }
	float getheight() { return height; }
	Point getPosition() { return position; }
protected:
	float width;
	float height;
	Point position;
};

