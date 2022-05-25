#pragma once
#include "Types.h"
class RectObject
{
public:
	virtual void Draw() = 0;
	virtual void HandleWindowReshape() = 0;
	float getWidth() { return width; }
	float getHeight() { return height; }
	Point getPosition() { return position; }
	void SetPosition(Point position) { this->position = position; }
protected:
	float width;
	float height;
	Point position;
};

