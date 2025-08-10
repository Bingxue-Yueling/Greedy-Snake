#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

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
		void Start();
		void Update();
		void UpdateMap();
		void NextTarget();
		bool CheckCollision();
	};
}
