#pragma once
#include "Ball.h"
#include "Brick.h"
#include "Rocket.h"
#include <vector>
#include <string>
#include <map>
#include <GL/freeglut_std.h>
using namespace std;

class Game 
{
public:
	static float window_width;
	static float window_height;

	//Game(map<int, string>& level_paths, int start_level);
	Game();
	void HandleWindowReshape();
	void Update();
	void Draw();
	void MouseMove(int mouse_x);
	void PauseUnpause();
	
private:
	Ball ball;
	vector<Brick> bricks;
	Rocket rocket;
	//map<int, string> level_paths;
	bool isActive = false;
	int current_level;
	int balls_left;
	int bricks_left;
	int row_number;
	void HandleCollision();
	bool isColision(Brick& br);
	void LoadLevel();
	void NewBall();
	
	//void EndGame();
};



