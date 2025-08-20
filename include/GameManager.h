#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <thread>
#include <mutex>
#include <atomic>

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
		mutable std::mutex mutex_; // 添加互斥锁
		std::atomic<bool> gameOver;
		bool autoMove;
		std::chrono::milliseconds autoMoveInterval;
		std::unique_ptr<std::thread> autoMoveThread;
	};
}
