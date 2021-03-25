#include "sort.h"
using namespace ex1;

void main() {
	Input input;
	input.getUserInput();
	input.printArr();
	Sort::sortMenu(input.getArr());
}