#include "Game.h"
#include <GL\freeglut.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream> 
float Game::window_width;
float Game::window_height;

using namespace std;

Game::Game() {
	LoadLevel();
}

void Game::MouseMove(int mouse_x) {
	if (!isActive) return;
	rocket.Move(mouse_x);
}

void Game::PauseUnpause() {
	isActive = !isActive;
}


void Game::Draw() {
	string s = to_string(balls_left - 1);
	const char* c = s.c_str();
	glRasterPos2f(Game::window_width - 50, Game::window_height - 50);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)c);
	rocket.Draw();
	ball.Draw();
	for (auto& brick : bricks) {
		brick.Draw();
	}
}


void Game::HandleWindowReshape() {
	rocket.HandleWindowReshape();
	ball.HandleWindowReshape();
}

void Game::Update() {
	if (!isActive) return;
	ball.Move();
	HandleCollision();
}

void Game::NewBall() {
	ball.SetStartPosition();
	rocket.setStartPosition();
	balls_left--;
	isActive = false;
}


void Game::LoadLevel() {
	ifstream file("level_1.txt");
	vector<vector<int>> level;
	string str;
	int index = 0;
	while (getline(file, str)) {
		level.push_back(vector<int>());
		stringstream ss(str);
		std::istream_iterator<std::string> begin(ss);
		std::istream_iterator<std::string> end;
		std::vector<std::string> tokens(begin, end);
		for (auto& token : tokens) {
			level[index].push_back(stoi(token));
		}
		index++;

	}
	row_number = level.size();
	float width = Game::window_width / Brick::col_number;;
	for (int row = 0; row < row_number; row++)
	{
		for (int col = 0; col < Brick::col_number; col++)
		{
			float x = Game::window_width / (Brick::col_number * 2) + col * Game::window_width / Brick::col_number;
			Brick br( level[row][col], row, col);
			float h = br.getHeight();
			float y = h / 2 + row * h;
			br.SetPosition({ x,y });
			bricks.push_back(br);
		}
	}
	balls_left = 3;
}


bool Game::isColision(Brick& br) {
	if (br.GetStrength() <= 0) return false;
	float x = ball.getPosition().x;
	float y = ball.getPosition().y;
	float r = ball.getWidth() / 2;
	float h = br.getHeight();
	float w = br.getWidth();
	float col = br.getCol();
	float row = br.getRow();
	if (abs(x - col * w - w / 2 - 2) <= r + w / 2 && abs(y - row * h - h / 2 - 2) <= r + h / 2)
	{
		if (sqrt((col * w + w / 2 - x) * (col * w + w / 2 - x) + (row * h + h / 2 - y) * (row * h + h / 2 - y))- (w / 2 - 1) * sqrt(2.0) - r > r * (sqrt(2.0) - 1))
			return false;
		else
			return true;
	}
	return false;
}


void Game::HandleCollision() {
	float r = ball.getWidth() / 2;
	Point ball_pos = ball.getPosition();
	Point rocket_pos = rocket.getPosition();

	if (ball_pos.x - r <= 0)
	{
		ball.inverseSpeedX();
	}
	else if (ball_pos.y - r <= 0)
	{
		ball.inverseSpeedY();
	}
	else if (ball_pos.x + r >= Game::window_width)
	{
		ball.SetPosition({ Game::window_width - r,  ball.getPosition().y });
		ball.inverseSpeedX();
	}
	else if (ball_pos.y + r >= rocket_pos.y && ball_pos.y + r <= rocket_pos.y + rocket.getHeight() && ball_pos.x > rocket_pos.x - rocket.getWidth()/2 && ball_pos.x < rocket_pos.x + rocket.getWidth() /2)
	{
		float y = rocket_pos.y - 2 * r;
		ball_pos.y = y;
		ball.SetPosition(ball_pos);
		ball.inverseSpeedY();
	}
	else if (ball_pos.y > Game::window_height) {
		NewBall();
	}

	float w = bricks[0].getWidth();
	float h = bricks[0].getHeight();
	for (int i = 0; i < row_number; i++)
	{
		for (int j = 0; j < Brick::col_number; j++)
		{
			Brick& brick = bricks[i * Brick::col_number + j ];
			
			if (isColision(brick))
			{
				if (abs(ball_pos.x - brick.getCol() * w - w / 2) < abs(ball_pos.y - brick.getRow() * h - h / 2))
				{
					ball.inverseSpeedY();
				}
				else if (abs(ball_pos.x - brick.getCol() * w - w / 2) > abs(ball_pos.y - brick.getRow() * h - h / 2))
				{
					ball.inverseSpeedX();
				}
				else
				{
					if (ball.getSpeed().x > 0)
					{
						if (ball_pos.x < brick.getCol() * w + 1) {
							ball.inverseSpeedX();
						}
					}
					else if (ball_pos.x > (brick.getCol() + 1) * w - 1) {
						ball.inverseSpeedX();
					} 
					if (ball.getSpeed().y > 0)
					{
						if (ball_pos.y < brick.getRow() * h + 1) {
							ball.inverseSpeedY();
						} 
					}
					else if (ball_pos.y > (brick.getRow() + 1) * h - 1) {
						ball.inverseSpeedY();
					} 
				}
				brick.Hit();
				
				return;
			}
		}
	}
}
