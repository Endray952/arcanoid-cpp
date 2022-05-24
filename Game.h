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
	Game() {
		//Game::window_width = glutGet(GLUT_WINDOW_WIDTH);
		//Game::window_height = glutGet(GLUT_WINDOW_HEIGHT);
	};

	static float window_width;
	static float window_height;

	//Game(map<int, string>& level_paths, int start_level);
	void Update();
	void Draw();
	void MouseMove(int mouse_x);
	//void WindowResize();
private:
	//Ball ball;
	//vector<Brick> bricks;
	Rocket rocket;
	//map<int, string> level_paths;
	int current_level;
	int balls_left;

	//void LoadLevel();
	
	//void NewBall();
	//void EndGame();
};



