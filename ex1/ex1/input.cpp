#include "input.h"

namespace ex1
{

	bool Input::isValidNum(DynamicArr<char>& num) {
		int decimalLevel = num.size() - (num.find('.') + 2);

		return ((num.size() - 1 > 0) && decimalLevel >= 1 && decimalLevel <= 4);
	}

	void Input::arrSizeInput() {
		cout << "Enter Array Size: " << endl;
		cin >> _arrSize;
		while (_arrSize < 1) {
			cout << "Enter VALID Array Size > 0: " << endl;
			cin >> _arrSize;
		}

		_arr.resize(_arrSize);
	}

	void Input::getIndex() {
		cout << "Enter desired index: " << endl;
		cin >> _index;
		while (_index <= 0) {
			cout << "Enter VALID index > 0: " << endl;
			cin >> _index;
		}
	}

	void Input::getNumbers() {
		double number;
		DynamicArr<char> strNumber;
		char c = NULL;

		cin.ignore();
		cout << "Enter numbers: " << endl;
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

	void Input::getArrCopy(double *&numArr) {
		_arr.copy(numArr);
	}

	void Input::getUserInput() {
		arrSizeInput();
		getIndex();
		getNumbers();
	}

	void Input::printArr() {
		for (auto itr = _arr.begin(); itr != _arr.end(); itr++)
			cout << fixed << setprecision(4) << *itr << ", ";
		cout << endl;
	}
}