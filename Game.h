#pragma once
#include "Ball.h"
#include "Brick.h"
#include "Rocket.h"
#include <vector>
#include <string>
#include <map>
#include <GL/freeglut_std.h>
#include "Menu.h"
using namespace std;


class Game 
{
public:
	static float window_width;
	static float window_height;

	Game(Menu& menu);
	void HandleWindowReshape();
	void Update();
	void Draw();
	void MouseMove(int mouse_x);
	void PauseUnpause();
	void LoadLevel(string path);
	void EndGame();
private:
	Menu& pMenu;
	Ball ball;
	vector<Brick> bricks;
	Rocket rocket;
	bool isActive = false;
	int current_level;
	int balls_left;
	int bricks_left;
	int row_number;
	void HandleCollision();
	bool isCollision(Brick& br);
	void NewBall();
};


