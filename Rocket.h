#pragma once

#include "Types.h"
#include "RectObject.h"

class Rocket : public RectObject
{
public:
	Rocket();
	void Draw() override;
	void Move(float mouse_pos_x);
	void HandleWindowReshape() override;
private:
	
};

