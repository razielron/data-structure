#include "input.h"

namespace ex2
{

	bool Input::isValidNum(DynamicArr<char>& num) {
		int decimalLevel = num.size() - (num.find('.') + 2);

		return ((num.size() - 1 > 0) && decimalLevel >= 1 && decimalLevel <= 4);
	}

	void Input::arrSizeInput() {
		cin >> _arrSize;
		if (_arrSize < 1) {
			cout << "Wrong Input" << endl;
			exit(-1);
		}

		_arr.resize(_arrSize);
	}

	void Input::getIndex() {
		cin >> _index;
		if (_index <= 0) {
			cout << "Wrong Input" << endl;
			exit(-1);
		}
	}

	void Input::getNumbers() {
		double number;
		DynamicArr<char> strNumber;
		char c;

		cin.ignore();
		for (int i = 0; i < _arrSize; i++) {
			cin.get(c);
			while (c != '\n' && c != ' ') {
				strNumber.push_back(c);
				cin.get(c);
			}
			strNumber.push_back('\0');

			if (!isValidNum(strNumber)) {
				cout << "Wrong Input" << endl;
				exit(-1);
			}

			number = atof(strNumber.getArr()); //char* -> double
			_arr.push_back(number);
			strNumber.clear();
		}
	}

	/*void Input::getArrCopy(double*& numArr) {
		_arr.copy(numArr);
	}*/

	void Input::getUserInput() {
		arrSizeInput();
		getIndex();
		getNumbers();
	}
}