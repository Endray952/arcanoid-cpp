#pragma once

#include "Types.h"
#include "RectObject.h"

class Rocket : private RectObject
{
public:
	Rocket();
	
	void Draw() override;
	void Move(float mouse_pos_x);
	void HandleWindowResize(float width, float height);
private:
	
};

