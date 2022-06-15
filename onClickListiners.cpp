#include "Menu.h"
#include "onClickListiners.h"
#include <Windows.h>

void Button_1(Button* btn) {
	Menu* menu = btn->getPToMenu();
	if (btn != nullptr && menu->game != nullptr) {
		menu->isGame = true;
		menu->game->LoadLevel("level_1.txt");
	}
}


void Button_2(Button* btn) {
	Menu* menu = btn->getPToMenu();
	if (btn != nullptr && menu->game != nullptr) {
		menu->isGame = true;
		menu->game->LoadLevel("level_2.txt");
	}
}



