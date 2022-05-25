#include "Brick.h"
#include <GL/glut.h>
#include "Game.h"
int Brick::col_number = 15;
Brick::Brick( int strength, int row, int col) {
	this->strength = strength;
	this->col = col;
	this->row = row;
	width = Game::window_width / Brick::col_number;
	height = 20;
}

void Brick::Draw() {
	if (strength <= 0) return;
	if (strength == 2) {
		glColor3f(0.1, 0.2, 0.8);
	}
	else {
		glColor3f(1,0.8, 0.2);
	}
	
	glRectf(position.x - width / 2 + 1, position.y + height / 2 -1, position.x + width / 2 - 1, position.y - height / 2 + 1);
}

void Brick::Hit() {
	strength--;
}