#include "sort.h"
#include "input.h"
using namespace ex1;

int main() {
	Input input;
	input.getUserInput();
	Sort::sortMenu(input.getArr(), input.geti());
}