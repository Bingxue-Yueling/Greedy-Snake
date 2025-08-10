#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

namespace Utils
{
	class PrintUtil
	{
	public:
		PrintUtil();
		~PrintUtil();
		void static SetColor(int color);
		void static ColorText(const std::string &text, int color);
		void static ClearScreen();
	};
}
