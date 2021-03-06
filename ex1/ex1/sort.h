#pragma once
#include "dynamicArr.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <math.h>
using namespace std;

namespace ex1
{
	class Sort {
	public:
		static double insertionSort(double *&num, int size, int index);
		static double selectionSort(double*& Arr, int left, int right, int i);
		static double quintileSort(double** num, int size, int index);
		static void bubbleSort(double** num, int size);
		static double medianFinder(double*& arr, int n, int size);
		static int partition(double*& Arr, int left, int right);
		static void swap(double* num1, double* num2);
		static void swap(double*& Arr, int& left, int& right);
		static void printArr(double*& num, int size);
		static void sortMenu(DynamicArr<double>& arr, int i);
	};
	 

}