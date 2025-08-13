#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "PrintUtil.h"

using namespace std;
using namespace Utils;

class Menu
{
private:
	vector<string> mainMenu = {
		"Start Game",
		"Options",
		"Help",
		"Exit Game"};
	vector<string> option = {
		"Easy",
		"Normal",
		"Hard",
		"Back to Main Menu"};
	vector<string> help = {
		"w: Move Up",
		"s: Move Down",
		"a: Move Left",
		"d: Move Right",
		"Back to Main Menu"};

public:
	int mapSize[2] = {10, 10}; // 默认地图大小
	Menu();
	~Menu();
	void UpdateMenuFrame(vector<string> options, int selectId = 0, bool delay = false);
	void UpdateMainMenu(int selectId = 0, bool delay = false);
	void UpdateOptionMenu(int selectId = 0, bool delay = false);
	void UpdateHelpMenu(int selectId = 0, bool delay = false);
	void SelectMainMenu();
	void SelectOptionMenu();
	void SelectHelpMenu();
	void WriteChar(short x, short y, const string *str);
};
