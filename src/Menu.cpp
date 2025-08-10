#include "Menu.h"

Menu::Menu()
{
	/*fg_pattern = new string(fg);
	bg_pattern = new string(bg);*/
}
Menu::~Menu()
{
	// delete fg_pattern, bg_pattern;
}

void Menu::UpdateMenu(int selectId, bool delay)
{
	int sleepTime = 50;
	cout << "** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**    _____                       _               _____                _           **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**   / ____|                     | |             / ____|              | |          **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**  | |  __  _ __  ___   ___   __| | _   _      | (___   _ __    __ _ | | __ ___   **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**  | | |_ || '__|/ _ \\ / _ \\ / _` || | | |      \\___ \\ | '_ \\  / _` || |/ // _ \\  **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**  | |__| || |  |  __/|  __/| (_| || |_| |      ____) || | | || (_| ||   <|  __/  **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**   \\_____||_|   \\___| \\___| \\__,_| \\__, |     |_____/ |_| |_| \\__,_||_|\\_\\\\___|  **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                    __/ |                                        **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                   |___/                                         **" << endl;
	if (delay)
		Sleep(sleepTime);

	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                                                                 **" << endl;
	if (selectId == 0)
	{
		PrintUtil::SetColor(2);
	}
	cout << "**                                   Start  Game                                   **" << endl;
	PrintUtil::SetColor(6);
	if (delay)
		Sleep(sleepTime);
	if (selectId == 1)
	{
		PrintUtil::SetColor(2);
	}
	cout << "**                                     Options                                     **" << endl;
	PrintUtil::SetColor(6);
	if (delay)
		Sleep(sleepTime);
	if (selectId == 2)
	{
		PrintUtil::SetColor(2);
	}
	cout << "**                                    Exit Game                                    **" << endl;
	PrintUtil::SetColor(6);
	if (delay)
		Sleep(sleepTime);
	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                            @ Bingxue Yueling Studio                             **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                 Date 2024-11-12                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                              All Right Reserved.                                **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
}

// 在屏幕输出字符
void Menu::WriteChar(short x, short y, const string *str)
{
	// 获取屏幕输出句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// 获取输出坐标
	SetConsoleCursorPosition(hOut, {y, x});

	// 输出相应的字符
	cout << *str;
}
