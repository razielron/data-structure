#pragma once
#include "input.h"
using namespace std;

namespace ex1
{
	class Sort {
	public:
		static void insertionSort(double *&num, int size);
		static void sortMenu(DynamicArr<double> &arr);
		static void printArr(double *&num, int size);
	};
	 

}