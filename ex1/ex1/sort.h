#pragma once
#include "input.h"
using namespace std;

namespace ex1
{
	class Sort {
	public:
		static void insertionSort(double *&num, int size);
		static void sortMenu(DynamicArr<double> &arr, int i);
		static void printArr(double *&num, int size);
		static double selectionSort(double*& Arr, int left, int right, int i);
		static int partition(double*& Arr, int left, int right);
		static void swap(double*& Arr, int& left, int& right);

	};
	 

}