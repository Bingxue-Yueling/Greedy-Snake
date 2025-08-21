#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include "Menu.h"
#include "GameManager.h"

int main()
{
	// 设置控制台输出编码为UTF-8
	SetConsoleOutputCP(CP_UTF8);

	// 创建菜单并显示主菜单
	Menu menu;
	menu.SelectMainMenu();
	return 0;
}