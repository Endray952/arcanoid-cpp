#include "Rocket.h"
#include <GL/glut.h>
#include <iostream>
#include "Game.h"

Rocket::Rocket() {
	//double w = glutGet(GLUT_WINDOW_WIDTH);
	//double h = glutGet(GLUT_WINDOW_HEIGHT);
	float w = Game::window_width;
	float h = Game::window_height;
	//Rect initial_position = { { 50.0, 290.0 }, { 80.0, 8.0 } };
	float height1 = 8;
	float width1 = w / 10;
	Rect initial_position = { { w / 2, h - height1 }, {  w / 2 + width1, h} };
	position = initial_position;


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
	//glRectf(position.LeftTop.x, position.LeftTop.y, position.RighBottom.x, position.RighBottom.y);
	glRectf(pos.x - width / 2, pos.y + height / 2, pos.x + width / 2, pos.y - height / 2);
}

void Rocket::Move(float mouse_pos_x) {
	//std::cout << position.RighBottom.x << "  " << position.LeftTop.x << std::endl;
	//int width = 200;

	/*float width = position.RighBottom.x - position.LeftTop.x;
	float left = mouse_pos_x - width / 2;
	float rigth = mouse_pos_x + width / 2;
	if (left > 0 && rigth < glutGet(GLUT_WINDOW_WIDTH)) {
		position.LeftTop.x = mouse_pos_x - width / 2;
		position.RighBottom.x = mouse_pos_x + width / 2;
	}*/

	//std::cout << width << std::endl;


	/*float width1 = position.RighBottom.x - position.LeftTop.x;
	float left = mouse_pos_x - width1 / 2;
	float rigth = mouse_pos_x + width1 / 2;
	if (left > 0 && rigth < glutGet(GLUT_WINDOW_WIDTH)) {
		position.LeftTop.x = mouse_pos_x - width1 / 2;
		position.RighBottom.x = mouse_pos_x + width1 / 2;
	}*/


	float left = mouse_pos_x - width / 2;
	float rigth = mouse_pos_x + width / 2;
	if (left > 0 && rigth < glutGet(GLUT_WINDOW_WIDTH)) {
		pos.x = mouse_pos_x ;
		//position.RighBottom.x = mouse_pos_x + width1 / 2;
	}

}