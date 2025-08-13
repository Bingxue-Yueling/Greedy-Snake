#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <thread>

#include "Snake.h"

namespace Managers
{
	class GameManager
	{
	public:
		int row, col;
		std::pair<int, int> target;
		Snake snake;

		GameManager(int r = 10, int c = 10);
		~GameManager();
		void GameStart();
		void GameOver();
		void GameUpdate();
		void UpdateMap();
		void NextTarget();
		bool CheckCollision();
		void StartAutoMove();
		void UpdateAutoMove();
		void StopAutoMove();

	private:
		bool gameOver, autoMove = true;
		std::chrono::milliseconds autoMoveInterval = std::chrono::milliseconds(1000);
		std::unique_ptr<std::thread> autoMoveThread;
	};
}
