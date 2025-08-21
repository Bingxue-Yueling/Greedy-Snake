#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include "Menu.h"
#include "GameManager.h"
#include "LogUtil.h"

int main()
{
	LogUtil logUtil;
	logUtil.InitLogger();

	spdlog::info("Game started");
	// 设置控制台输出编码为UTF-8
	SetConsoleOutputCP(CP_UTF8);

	// 创建菜单并显示主菜单
	Menu menu;
	menu.SelectMainMenu();

	spdlog::info("Game exited");
	spdlog::default_logger()->flush(); // 立即刷新
	return 0;
}