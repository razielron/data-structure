#pragma once
#include "dynamicArr.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

namespace ex2
{
	class Input {
	private:
		DynamicArr<double> _arr;
		int _arrSize = 0;
		int _index = 0;
		string _inputFileName;
		string _outputFileName;

		bool isValidNum(string& num);
		void arrSizeInput();
		void getIndex();
		void getFilesName();
		void getNumbers();

	public:
		int getSize() { return _arrSize; }
		int geti() { return _index; }
		string getInputFileName() { return _inputFileName; }
		string getOutputFileName() { return _outputFileName; }
		double* getArr() { return _arr.getArr(); }
		void getUserInput();
	};
}