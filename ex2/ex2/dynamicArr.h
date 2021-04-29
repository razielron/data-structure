#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#define rcastcc reinterpret_cast<const char*>
#define rcastc reinterpret_cast<char*>

namespace ex2
{
	template<class T>
	class DynamicArr {

	protected:
		T* _array;
		const int GROTH_FACTOR = 2;
		int _logSize;
		int _phySize;

	public:
		DynamicArr(int size = 1);
		DynamicArr(T);
		DynamicArr(istream& in);
		~DynamicArr();

	public:
		// returns size of array
		int size() const { return _logSize; }
		//returns array
		T* getArr() { return _array; }
		//returns the first element in the array
		const T& front() const { return _array[0]; }
		// return true if the array is empty
		bool empty() const { return _logSize == 0; }
		// returns the physical size
		int capacity() const { return _phySize; }
		//clears the array
		void clear() { _logSize = 0; }

	public:
		T operator[](int idx) { return _array[idx]; }
		T operator[](int idx) const { return _array[idx]; }
		bool operator!() const { return this == nullptr; }

	public:
		// append at the end
		void push_back(T element);
		//delete at given position
		void erase(int pos);
		//insert at given position, and increse the array accordingly
		void insertAt(T element, int pos);
		// doubles capacity if it has to and deletes reference to current array
		void resize();
		// set array capacity by given number
		void resize(int newSize);
		// copies original array into temp
		void copy(T* element);
		// returns element in a given position
		T at(int pos);
		//returns an  by given parameter
		int find(T value);
		//returns an element by given parameter
		T find(int id);
		//returns sub-string by range
		T* substr(int begin, int end = 0);
		//Swaps elements
		void swap(T al1, T el2);
		//deletes all values in the array
		void deleteValues();

	};

	/*------------------------DynamicArr Functions Implementation------------------------*/
	template<class T>
	DynamicArr<T>::DynamicArr(int size) : _logSize(0), _phySize(size) {
		if (size < 0) {
			exit(-1);
		}
		try {
			_array = _phySize ? new T[_phySize] : nullptr;
		}
		catch (bad_alloc& err) {
			cout << err.what() << endl;
			exit(1);
		}
	};

	template<class T>
	DynamicArr<T>::DynamicArr(T element) : _logSize(1), _phySize(2) {
		if (!element) {
			exit(-1);
		}

		try {
			_array = new T[_phySize];
			_array[0] = element;
		}
		catch (bad_alloc& err) {
			cout << err.what() << endl;
			exit(1);
		}
	}

	template<class T>
	DynamicArr<T>::DynamicArr(istream& in) : _logSize(0) {
		if (!in) {
			exit(1);
		}

		in.read(rcastc(&_phySize), sizeof(int));
		if (!in.good()) {
			exit(1);
		}

		try {
			_array = new T[_phySize];
		}
		catch (bad_alloc& err) {
			cout << err.what() << endl;
			exit(1);
		}
	};

	template<class T>
	DynamicArr<T>::~DynamicArr() {
		delete[] _array;
	}

	//deletes all values in the array
	template<class T>
	void DynamicArr<T>::deleteValues() {
		for (int i = 0; i < _logSize; i++) {
			delete _array[i];
		}
	}

	template<class T>
	void DynamicArr<T>::push_back(T element) {
		if (_logSize == _phySize) {
			resize();
		}
		_array[_logSize] = element;
		_logSize++;
	}

	template<class T>
	void DynamicArr<T>::erase(int pos) {
		if (pos > _logSize || pos < 0) {
			exit(1);
		}
		delete _array[pos];
		for (int i = pos; i < _logSize - 1; i++)
			_array[i] = _array[i + 1];
		delete _array[_logSize - 1];
		_logSize--;
	}

	template<class T>
	void DynamicArr<T>::insertAt(T element, int pos) {
		if (pos > _logSize || pos < 0) {
			exit(1);
		}

		if (_logSize == _phySize) {
			resize();
		}
		_logSize++;

		for (int i = _logSize - 1; i >= pos; i--) {
			if (i == pos)
				_array[pos] = element;
			else {
				_array[i] = _array[i - 1];
			}
		}
	}

	template<class T>
	void DynamicArr<T>::resize(int newSize) {
		try {
			_phySize = newSize;
			T* temp = new T[_phySize];
			copy(temp);
			delete[] _array;
			_array = temp;
		}
		catch (bad_alloc& err) {
			cout << err.what() << endl;
			exit(1);
		}
	}

	template<class T>
	void DynamicArr<T>::resize() {
		try {
			_phySize *= GROTH_FACTOR;
			T* temp = new T[_phySize];
			copy(temp);
			delete[] _array;
			_array = temp;
		}
		catch (bad_alloc& err) {
			cout << err.what() << endl;
			exit(1);
		}
	}

	template<class T>
	T* DynamicArr<T>::substr(int begin, int end) {
		return _array + begin;
	}

	template<class T>
	void DynamicArr<T>::copy(T* element) {
		if (!element) {
			exit(1);
		}

		for (int i = 0; i < _logSize; i++) {
			element[i] = _array[i];
		}
	}

	template<class T>
	T DynamicArr<T>::at(int pos) {
		if (pos > _logSize || pos < 0) {
			exit(1);
		}
		return _array[pos];
	}

	template<class T>
	int DynamicArr<T>::find(T value) {
		for (int i = 0; i < _logSize; i++) {
			if (_array[i] == value)
				return i;
		}

		return size();
	}




	template<class T>
	T DynamicArr<T>::find(int id) {
		for (int i = 0; i < _logSize; i++) {
			if (_array[i]->getId() == id)
				return _array[i];
		}

		exit(1);
	}

	template<class T>
	void DynamicArr<T>::swap(T el1, T el2) {
		T temp = el1;
		el1 = el2;
		el2 = temp;
	}
}