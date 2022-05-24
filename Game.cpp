#include "Game.h"
float Game::window_width;
float Game::window_height;

void Game::MouseMove(int mouse_x) {
	rocket.Move(mouse_x);
	//Draw();
}

void Game::Draw() {
	rocket.Draw();
}