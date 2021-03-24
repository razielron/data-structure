#pragma once
#include "dynamicArr.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace ex1
{
	class Input {
	private:
		DynamicArr<double> _arr;
		int _arrSize = 0;
		int _index = 0;

		bool isValidNum(DynamicArr<char>& num);
		void getArrSize();
		void getIndex();
		void getNumbers();

	public:
		void getUserInput();
		void printArr();
	};
}