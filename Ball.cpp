#include "Ball.h"
#include <GL/glut.h>
#include <math.h>
#include "Game.h"

Ball::Ball() {
	SetStartPosition();
	speed.x = 4;
	speed.y = 4;
}


void Ball::SetStartPosition() {
	float w = Game::window_width;
	float h = Game::window_height;
	HandleWindowReshape();
	Point ini_pos = { w / 2 - width / 2, h - height * 2};
	position = ini_pos;
}


void Ball::Draw() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (float i = 0; i < 2 * 3.14; i += 3.14 / 4)
	{
		glVertex2f(position.x + height * sin(i), position.y + height * cos(i));
	}
	glEnd();
}

void Ball::HandleWindowReshape() {
	width = Game::window_width / 70;
	height = Game::window_height / 70;
	position.y = Game::window_height - height * 2;
}


void Ball::Move() {
	position.x += speed.x;
	position.y += speed.y;

	/*float x = position.x;
	float y = position.y;
	float dx = speed.x;
	float dy = speed.y;
	float r = width / 2;
	if (x - r <= 0)
	{
		x = r;
		dx *= -1;
	}
	else if (y - r <= 0)
	{
		y = r;
		dy *= -1;
	}
	else if (x + r >= Game::window_width)
	{
		x = Game::window_width - r;
		dx *= -1;
	}*/
	/*else if (y + r >= r_y && y + r <= r_y + r_h && x > r_x && x < r_x + r_w)
	{
		y = r_y - r;
		dy *= -1;
	}*/
}