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

	int selectId = 0;

	Menu menu;
	menu.UpdateMenu(selectId, true);
	while (true)
	{
		char key = _getch();
		Utils::PrintUtil::ClearScreen();
		switch (key)
		{
		case 'w':
			selectId += 2;
			selectId %= 3;
			break;
		case 's':
			selectId++;
			selectId %= 3;
			break;
		case '\r':
		{
			if (selectId == 0)
			{
				Managers::GameManager gameManager(20, 20);
				gameManager.Start();
			}
			break;
		}
		case 'q':
			menu.UpdateMenu(selectId);
			cout << endl;
			cout << "按任意键退出……" << endl;
			_getch(); // Wait for any key press before exiting
			return 0; // Exit the program
			break;
		default:
			break;
		}

		// menu.UpdateMenu(selectId);
	}
	return 0;
}