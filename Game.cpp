#include "Game.h"
float Game::window_width;
float Game::window_height;


void Game::MouseMove(int mouse_x) {
	rocket.Move(mouse_x);
	//Draw();
}


void Game::Draw() {
	rocket.Draw();
	ball.Draw();
}


void Game::HandleWindowReshape() {
	rocket.HandleWindowReshape();
	ball.HandleWindowReshape();
}

void Game::Update() {
	ball.Move();
	HandleCollision();
}

void Game::HandleCollision() {
	float r = ball.getWidth() / 2;
	Point ball_pos = ball.getPosition();
	Point rocket_pos = rocket.getPosition();
	if (ball_pos.x - r <= 0)
	{
		//ball_pos.x = r;
		ball.speed.x *= -1;
	}
	else if (ball_pos.y - r <= 0)
	{
		//y = r;
		ball.speed.y *= -1;
	}
	else if (ball_pos.x + r >= Game::window_width)
	{
		//x = 300 - r;
		ball.speed.x *= -1;
	}
	else if (ball_pos.y + r >= rocket_pos.y && ball_pos.y + r <= rocket_pos.y + rocket.getheight() && ball_pos.x > rocket_pos.x - rocket.getWidth()/2 && ball_pos.x < rocket_pos.x + rocket.getWidth() /2)
	{
		//y = r_y - r;
		ball.speed.y *= -1;
	}
	else if (ball_pos.y > Game::window_height) {
		ball.SetStartPosition();
	}

}