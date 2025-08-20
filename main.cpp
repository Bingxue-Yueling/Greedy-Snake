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
	try
	{
		Menu menu;
		menu.SelectMainMenu();
	}
	catch (const std::exception &e)
	{
		spdlog::error("Exception: {}", e.what());
	}
	catch (...) // 捕获其他异常
	{
		spdlog::error("Unknown exception!");
	}

	spdlog::info("Game exited");
	spdlog::default_logger()->flush();  // 立即刷新
	system("pause");
	return 0;
}