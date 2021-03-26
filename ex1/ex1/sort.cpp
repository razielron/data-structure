#include "sort.h"

namespace ex1
{
	double Sort::insertionSort(double *&num, int size, int index) {
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
        return num[index];
	}
    
    double Sort::selectionSort(double*& Arr, int left, int right, int i) {
        int pivot;
        int leftPart;

        pivot = partition(Arr, left, right);
        leftPart = pivot - left + 1;
        if (i == leftPart)
            return Arr[pivot];
        if (i < leftPart)
            return selectionSort(Arr, left, pivot - 1, i);
        else
            return selectionSort(Arr, pivot + 1, right, i - leftPart);
    }

    int Sort::partition(double*& Arr, int left, int right) {
        if (left == right)
            return left;
        if (left < right) {
            if (Arr[left] > Arr[right]) {
                swap(Arr, left, right);
                right++;
            }
            else {
                right--;
            }
        }
        else {
            if (Arr[left] > Arr[right]) {
                right++;
            }
            else {
                swap(Arr, left, right);
                right--;
            }
        }
        
        return partition(Arr, left, right);
    }

    void Sort::swap(double*& Arr, int& left, int& right) {
        double temp = Arr[left];
        Arr[left] = Arr[right];
        Arr[right] = temp;
        temp = left;
        left = right;
        right = temp;
    }

    void Sort::printArr(double *&num, int size) {
        for (int i = 0;i < size;i++) {
            cout << (num)[i] << " ";
        }
        cout << endl;
    }


    void Sort::sortMenu(DynamicArr<double> &arr, int i) {
        int size = arr.size();
        double* copiedArr = new double[size];
        arr.copy(copiedArr);
        cout << endl << "Insersion sort:" << endl;
        cout << "The i number is: " << insertionSort(copiedArr, size, i) << endl;
        printArr(copiedArr, size);
        delete[] copiedArr;

        copiedArr = new double[size];
        arr.copy(copiedArr);
        cout << endl << "Selection sort:" << endl;
        cout << "The i number is: " << selectionSort(copiedArr, 0, size - 1, i) << endl;
        printArr(copiedArr, size);
    }
}
