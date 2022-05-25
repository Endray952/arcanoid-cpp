#include "Game.h"
float Game::window_width;
float Game::window_height;


void Game::MouseMove(int mouse_x) {
	if (!isActive) return;
	rocket.Move(mouse_x);
	//Draw();
}


void Game::Draw() {
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
	isActive = false;
}


void Game::LoadLevel() {
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 15; col++)
		{
			float x = Game::window_width / 30 + col * Game::window_width / 15;
			float y = 20 / 2 + row * 20;
			Brick br({ x, y }, 2, row, col);
			bricks.push_back(br);
		}
	}
	
}


bool Game::isColision(Brick& br) {
	//float x = b.x, y = b.y, r = b.r, c = br.col, w = br.w, row = br.row, h = br.h;
	if (br.GetStrength() <= 0) return false;
	float x = ball.getPosition().x;
	float y = ball.getPosition().y;
	float r = ball.getWidth() / 2;
	float h = br.getHeight();
	float w = br.getWidth();
	float c = br.col;
	float row = br.row;
	if (abs(x - c * w - w / 2 - 2) <= r + w / 2 && abs(y - row * h - h / 2 - 2) <= r + h / 2)
	{
		if (sqrt((c * w + w / 2 - x) * (c * w + w / 2 - x) + (row * h + h / 2 - y) * (row * h + h / 2 - y))
			- (w / 2 - 1) * sqrt(2.0) - r > r * (sqrt(2.0) - 1))
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
	else if (ball_pos.y + r >= rocket_pos.y && ball_pos.y + r <= rocket_pos.y + rocket.getHeight() && ball_pos.x > rocket_pos.x - rocket.getWidth()/2 && ball_pos.x < rocket_pos.x + rocket.getWidth() /2)
	{
		float y = rocket_pos.y - 2 * r;
		ball_pos.y = y;
		ball.SetPosition(ball_pos);
		ball.speed.y *= -1;
	}
	else if (ball_pos.y > Game::window_height) {
		NewBall();
	}

	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			Brick& b = bricks[i * 15 + j ];
			float w = b.getWidth();
			float h = b.getHeight();
			if (isColision(b))
			{
				if (abs(ball_pos.x - b.col * w - w / 2) < abs(ball_pos.y - b.row * h - h / 2))
				{
					ball.speed.y *= -1;
				}
				else if (abs(ball_pos.x - b.col * w - w / 2) > abs(ball_pos.y - b.row * h - h / 2))
				{
					ball.speed.x *= -1;
				}
				else
				{
					if (ball.speed.x > 0)
					{
						if (ball_pos.x < b.col * w + 1) ball.speed.x *= -1;
					}
					else if (ball_pos.x > (b.col + 1) * w - 1) ball.speed.x *= -1;
					if (ball.speed.y > 0)
					{
						if (ball_pos.y < b.row * h + 1) ball.speed.y *= -1;
					}
					else if (ball_pos.y > (b.row + 1) * h - 1) ball.speed.y *= -1;
				}
				b.Hit();
				
				return;
			}
		}
	}
}
