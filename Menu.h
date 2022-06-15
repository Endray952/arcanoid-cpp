#pragma once
#include <vector>
#include <map>
#include "Button.h"
#include "Types.h"
#include <iostream>
#include "Game.h"

using namespace std;

class Game;

class Menu
{
public:
	Menu(const string& path);
	void Render();
	void FindFocus(int x, int y);
	void HandleClick();
	void MakeTransitionTo(int id);
	bool isGame = false;
	Game* game;
private:
	Button* current_button = nullptr;
	vector<Button>* current_submenu;
	map<int, vector<Button>> menu_holder;

	void MenuFromConfig(const string& path);
	inline void ParseMenu(ifstream& file);
	inline void ParseButton(ifstream& file, vector<Button>& buttons);

};



