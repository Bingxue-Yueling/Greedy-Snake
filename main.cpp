#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include "Menu.h"
#include "GameManager.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	Menu menu;
	menu.SelectMainMenu();
	return 0;
}