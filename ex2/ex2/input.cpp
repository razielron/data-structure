#include "input.h"

namespace ex2
{

	bool Input::isValidNum(string& num) {
		char c;
		for (int i = 0;i < num.length();i++) {
			c = num[i];
			if (!(c >= '0' && c <= '9') && (c == '-' && i != 0))
				return false;
		}
		return true;
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
		string strNumber;
		char c;

		ifstream myfile(_inputFileName, ios::in);
		while (myfile.get(c)) {
			if (c != '\n')
				strNumber.push_back(c);
			else if (!isValidNum(strNumber)) {
				cout << "Wrong Input" << endl;
				exit(-1);
			}
			else {
				number = stod(strNumber); //string -> double
				_arr.push_back(number);
				strNumber.clear();
			}
		}
		if (!strNumber.empty()) {
			number = stod(strNumber); //string -> double
			_arr.push_back(number);
		}

		if (_arr.size() != _arrSize) {
			cout << "Wrong Input" << endl;
			exit(-1);
		}
	}

	void Input::getFilesName() {
		cin>>_inputFileName;
		if (_inputFileName.find(".txt")==string::npos)
			_inputFileName += ".txt";
		cin>>_outputFileName;
		if (_outputFileName.find(".txt")==string::npos)
			_outputFileName += ".txt";
		
	}

	void Input::getUserInput() {
		arrSizeInput();
		getIndex();
		getFilesName();
		getNumbers();
	}
}