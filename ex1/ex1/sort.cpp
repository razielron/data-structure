#include "sort.h"

namespace ex1
{
	void Sort::insertionSort(double *&num, int size) {
        int i, j;
        double temp;
        for (i = 1; i < size ; i++)
        {
            temp = (num)[i];
            j = i - 1;

            while (j >= 0 && (num)[j] > temp)
            {
                (num)[j + 1] = (num)[j];
                j = j - 1;
            }
            (num)[j + 1] = temp;
        }
	}

    void Sort::printArr(double *&num, int size) {
        for (int i = 0;i < size;i++) {
            cout << (num)[i] << " ";
        }
        cout << endl;
    }


    void Sort::sortMenu(DynamicArr<double> &arr) {
        int size = arr.size();
        double* copiedArr = new double[size];
        arr.copy(copiedArr);
        insertionSort(copiedArr, size);
        printArr(copiedArr, size);
        delete[] copiedArr;
    }
}