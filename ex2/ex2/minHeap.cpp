#include "minHeap.h"

namespace ex2
{
	MinHeap::MinHeap(int max) {
		_data = new double[max];
		_maxSize = max;
		_heapSize = 0;
		_allocated = 1;
	}

	MinHeap::MinHeap(double a[], int n) {
		_heapSize = _maxSize = n;
		_data = a;
		_allocated = 0;

		for (int i = n / 2 - 1;i >= 0;i--)
			fixHeap(i);
	}

	MinHeap::~MinHeap() {
		if (_allocated)
			delete[] _data;
		_data = nullptr;
	}

	int MinHeap::Parent(int node) {
		return (node - 1) / 2;
	}

	int MinHeap::Left(int node) {
		return 2*node + 1;
	}

	int MinHeap::Right(int node) {
		return 2 * node + 2;
	}

	void MinHeap::swap(double& a, double& b)
	{
		double temp = a;
		a = b;
		b = temp;
	}

	void MinHeap::fixHeap(int node){
		int min;
		int left = Left(node);
		int right = Right(node);

		if (left < _heapSize && _data[left] < _data[node])
			min = left;
		else min = node;
		if (right < _heapSize && _data[right] < _data[min])
			min = right;

		if (min != node) {
			swap(_data[node], _data[min]);
			fixHeap(min);
		}	
	}

	double MinHeap::deleteMin() {
		if (_heapSize < 1)
			exit(EXIT_FAILURE);
		double min = _data[0];
		_heapSize--;
		_data[0] = _data[_heapSize];
		fixHeap(0);
		return min;
	}

	void MinHeap::insert(double item) {
		if(_heapSize==_maxSize)
			exit(EXIT_FAILURE);
		int i = _heapSize;
		_heapSize++;

		while (i > 0 && _data[Parent(i)] > item) {
			_data[i] = _data[Parent(i)];
			i = Parent(i);
		}
		_data[i] = item;
	}


}