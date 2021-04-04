#pragma once
#include "dynamicArr.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace ex1
{
	class Input {
	private:
		DynamicArr<double> _arr;
		int _arrSize = 0;
		int _index = 0;

		bool isValidNum(DynamicArr<char>& num);
		void arrSizeInput();
		void getIndex();
		void getNumbers();

	public:
		int getSize() { return _arrSize; }
		int geti() { return _index; }
		DynamicArr<double>& getArr() { return _arr; }
		void getArrCopy(double *&arr);
		void getUserInput();
	};
}