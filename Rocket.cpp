#include "Rocket.h"
#include <GL/glut.h>
#include <iostream>
#include "Game.h"

Rocket::Rocket() {
	float w = Game::window_width;
	float h = Game::window_height;
	HandleWindowReshape();
	Point ini_pos = { w / 2 , h - height / 2 };
	position = ini_pos;
}

void Rocket::HandleWindowReshape() {
	width = Game::window_width / 12;
	height = Game::window_height / 70;
	position.y = Game::window_height - height / 2;
}

void Rocket::Draw() {
	glColor3f(0.2, 0.8, 0.1);
	glRectf(position.x - width / 2, position.y + height / 2, position.x + width / 2, position.y - height / 2);
}

void Rocket::Move(float mouse_pos_x) {
	float left = mouse_pos_x - width / 2;
	float rigth = mouse_pos_x + width / 2;
	if (left > 0 && rigth < glutGet(GLUT_WINDOW_WIDTH)) {
		position.x = mouse_pos_x ;
	}

}