#include "sort.h"
#include "input.h"
using namespace ex2;

int main() {
	Input input;
	input.getUserInput();
	double* arr = input.getArr();
	Sort::kWayMergeSort(arr, input.getSize(), input.geti());
	Sort::saveArray(arr, input.getSize(), input.getOutputFileName());
	Sort::printArr(arr, input.getSize());
}