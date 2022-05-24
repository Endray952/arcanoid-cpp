#include "Rocket.h"
#include <GL/glut.h>
#include <iostream>
#include "Game.h"

Rocket::Rocket() {
	float w = Game::window_width;
	float h = Game::window_height;
	HandleWindowResize(w, h);
	Point ini_pos = { w / 2 - width / 2, h - height / 2 };
	pos = ini_pos;
}

void Rocket::HandleWindowResize(float window_width, float window_height) {
	width = window_width / 10;
	height = window_height / 20;
}

void Rocket::Draw() {
	glColor3f(0.2, 0.8, 0.1);
	glRectf(pos.x - width / 2, pos.y + height / 2, pos.x + width / 2, pos.y - height / 2);
}

void Rocket::Move(float mouse_pos_x) {
	float left = mouse_pos_x - width / 2;
	float rigth = mouse_pos_x + width / 2;
	if (left > 0 && rigth < glutGet(GLUT_WINDOW_WIDTH)) {
		pos.x = mouse_pos_x ;
	}

}