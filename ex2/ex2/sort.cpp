#include "sort.h"

namespace ex2
{
    int Sort::partition(double* arr, int left, int right) {
        if (left == right)
            return left;
        if (left < right) {
            if (arr[left] > arr[right]) {
                swap(arr, left, right);
                right++;
            }
            else {
                right--;
            }
        }
        else {
            if (arr[left] > arr[right]) {
                right++;
            }
            else {
                swap(arr, left, right);
                right--;
            }
        }

        return partition(arr, left, right);
    }

    void Sort::swap(double* num1, double* num2) {
        double temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }

    void Sort::swap(double* arr, int& left, int& right) {
        int intTemp;
        double temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        intTemp = left;
        left = right;
        right = intTemp;
    }

    void Sort::printArr(double* arr, int size) {
        for (int i = 0;i < size;i++) {
            cout << (arr)[i] << " ";
        }
        cout << endl;
    }

    void Sort::quickSort(double* arr, int left, int right)
    {
        if (left < right)
        {
            int par = partition(arr, left, right);
            quickSort(arr, left, par - 1);
            quickSort(arr, par + 1, right);
        }
    }

    void Sort::merge(double* arr, int size, int k) {
        double min;
        int minKArr, kMaxIndex, t;
        double* mergedArr = new double[size];
        int indexesSize = (size % k) ? (k + 1) : k;
        int* indexes = new int[indexesSize];
        for (int i = 0;i < indexesSize;i++)
            indexes[i] = i * (size/k);
        for (int i = 0; i < size; i++) {
            kMaxIndex = (size / k)-1;
            t = 0;
            while (indexes[t] > kMaxIndex && t!=indexesSize) {
                t++;
                kMaxIndex = (t == indexesSize - 1) ? size - 1 : ((size / k) * (t+1)-1);
            }
            t = (t < indexesSize) ? t : t - 1;
            minKArr = t;
            min = arr[indexes[t]];
            for (int j = 0;j < indexesSize;j++) {
                kMaxIndex = (j == indexesSize - 1) ? size - 1 : ((size / k) * (j+1)-1);
                if (min > arr[indexes[j]] && indexes[j] <= kMaxIndex)
                {
                    min = arr[indexes[j]];
                    minKArr = j;
                }
            }
            mergedArr[i] = min;
            indexes[minKArr]++;
        }

        for (int i = 0;i < size;i++)
            arr[i] = mergedArr[i];

        delete[] mergedArr;
        delete[] indexes;
    }


	void Sort::kWayMergeSort(double* arr, int size, int k) {
        char cast;

        if (size < k){
            quickSort(arr, 0, size - 1);
            return;
        }
        double* temp;
        for (int i = 0; i < k;i++){
            temp = arr + (i * (size / k));
            kWayMergeSort(temp, size / k, k);
        }
        if (size % k) {
            temp = arr + (size - size % k);
            kWayMergeSort(temp, size%k, k);
        }
        
        merge(arr, size, k);
	}

}