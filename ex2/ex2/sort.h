#pragma once
#include "dynamicArr.h"
#include "minHeap.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <math.h>
using namespace std;

namespace ex2
{
	class Sort {
	public:
		static int partition(double* Arr, int left, int right);
		static void swap(double* num1, double* num2);
		static void swap(double* Arr, int& left, int& right);
		static void saveArray(double* arr, int size, string fileName);
		static void printArr(double* arr, int size);
		static void quickSort(double* arr, int left, int right);
		static void kWayMergeSort(double* arr, int size, int k);
		static void merge(double* arr, int size, int k);
	};
}
