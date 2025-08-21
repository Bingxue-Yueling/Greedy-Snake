#include "Menu.h"
#include <conio.h>
#include <GameManager.h>
#include <iomanip>

Menu::Menu()
{
	/*fg_pattern = new string(fg);
	bg_pattern = new string(bg);*/
}
Menu::~Menu()
{
	// delete fg_pattern, bg_pattern;
}

void Menu::UpdateMenuFrame(vector<string> options, int selectId, bool delay)
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

	for (std::vector<string>::iterator option = options.begin(); option != options.end(); ++option)
	{
		// 去掉星号后包含81个空格
		int leftPadding = (81 - option->length()) / 2;
		int rightPadding = 81 - option->length() - leftPadding;
		cout << "**" << string(leftPadding, ' ');
		if (selectId == option - options.begin())
		{
			PrintUtil::SetColor(2);
		}
		cout << *option;
		if (selectId == option - options.begin())
		{
			PrintUtil::SetColor(6);
		}
		cout << string(rightPadding, ' ') << "**" << endl;

		// cout << "**                              " << setw(21) << left << *option << "                              **" << endl;
		if (delay)
			Sleep(sleepTime);
	}

	cout << "**                                                                                 **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                            @ Bingxue Yueling Studio                             **" << endl;
	if (delay)
		Sleep(sleepTime);
	cout << "**                                 Date 2025-08-11                                 **" << endl;
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

void Menu::UpdateMainMenu(int selectId, bool delay)
{
	UpdateMenuFrame(mainMenu, selectId, delay);
}

void Menu::UpdateOptionMenu(int selectId, bool delay)
{
	UpdateMenuFrame(option, selectId, delay);
}

void Menu::UpdateHelpMenu(int selectId, bool delay)
{
	UpdateMenuFrame(help, selectId, delay);
}

void Menu::SelectMainMenu()
{
	int selectId = 0;
	UpdateMainMenu(selectId, true);
	while (true)
	{
		if (_kbhit()) // 检查是否有键盘输入
		{
			char key = _getch();
			Utils::PrintUtil::ClearScreen();
			switch (key)
			{
			case 'w':
				selectId += mainMenu.size() - 1;
				selectId %= mainMenu.size();
				break;
			case 's':
				selectId++;
				selectId %= mainMenu.size();
				break;
			case '\r':
			{
				switch (selectId)
				{
				case 0:
				{
					{
						Managers::GameManager gameManager(10, 10);
						gameManager.GameStart();
					}
					break;
				}
				case 1:
				{
					SelectOptionMenu();
					break;
				}
				case 2:
				{
					SelectHelpMenu();
					break;
				}
				case 3:
					UpdateMainMenu(selectId);
					cout << endl;
					cout << "Please press any key to exit..." << endl;
					_getch(); // Wait for any key press before exiting
					return;	  // Exit the program
				default:
					break;
				}
				break;
			}
			case 'q':
				UpdateMainMenu(selectId);
				cout << endl;
				cout << "Please press any key to exit..." << endl;
				_getch(); // Wait for any key press before exiting
				return;	  // Exit the program
			default:
				break;
			}
			UpdateMainMenu(selectId);
		}
	}
}

void Menu::SelectOptionMenu()
{
	int selectId = 0;
	UpdateOptionMenu(selectId, true);
	while (true)
	{
		char key = _getch();
		Utils::PrintUtil::ClearScreen();
		switch (key)
		{
		case 'w':
			selectId += option.size() - 1;
			selectId %= option.size();
			break;
		case 's':
			selectId++;
			selectId %= option.size();
			break;
		case '\r':
			switch (selectId)
			{
			case 0:
				_getch();
				return;
			case 1:
				mapSize[0] = 20;
				mapSize[1] = 20;
				_getch();
				return;
			case 2:
				mapSize[0] = 30;
				mapSize[1] = 30;
				_getch();
				return;
			case 3:
				return;
			default:
				break;
			}
			break;
		case 'q':
			return;
			break;
		default:
			break;
		}
		UpdateOptionMenu(selectId);
	}
}

void Menu::SelectHelpMenu()
{
	int selectId = 0;
	UpdateHelpMenu(selectId, true);
	while (true)
	{
		char key = _getch();
		Utils::PrintUtil::ClearScreen();
		switch (key)
		{
		case 'w':
			selectId += help.size() - 1;
			selectId %= help.size();
			break;
		case 's':
			selectId++;
			selectId %= help.size();
			break;
		case '\r':
			return;
		case 'q':
			return;
		default:
			break;
		}
		UpdateHelpMenu(selectId);
	}
}

// 在屏幕输出字符
void Menu::WriteChar(short x, short y, const string *str)
{
	// 获取屏幕输出句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// 获取输出坐标
	SetConsoleCursorPosition(hOut, {x, y});

	// 输出相应的字符
	cout << *str;
}
