#include "sort.h"

namespace ex2
{
    int Sort::partition(double*& arr, int left, int right) {
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

    void Sort::swap(double*& arr, int& left, int& right) {
        double temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        temp = left;
        left = right;
        right = temp;
    }

    void Sort::printArr(double*& arr, int size) {
        for (int i = 0;i < size;i++) {
            cout << (arr)[i] << " ";
        }
        cout << endl;
    }

    void Sort::quickSort(double*& arr, int left, int right)
    {
        if (left < right)
        {
            int par = partition(arr, left, right);
            quickSort(arr, left, par - 1);
            quickSort(arr, par + 1, right);
        }
    }

    void Sort::merge(double*& arr, int size, int k) {
        double min;
        int minKArr, kMaxIndex, t=0;
        double* mergedArr = new double[size];
        int indexesSize = (size % k) ? (k + 1) : k;
        int* indexes = new int[indexesSize];
        for (int i = 0;i < indexesSize;i++)
            indexes[i] = i * k;
        for (int i = 0; i < size; i++) {
            kMaxIndex = (size / k);
            while (indexes[t] >= kMaxIndex && t!=indexesSize) {
                kMaxIndex = (t == indexesSize - 1) ? size - 1 : ((size / k) * t);
                t++;
            }
            minKArr = t;
            min = arr[indexes[t]];
            for (int j = 0;j < indexesSize;j++) {
                kMaxIndex = (j == indexesSize - 1) ? size - 1 : ((size / k) * j);
                if (min > arr[indexes[j]] && indexes[j] < kMaxIndex)
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
    }


	void Sort::kWayMergeSort(double*& arr, int size, int k) {
        if (size < k){
            quickSort(arr, 0, size);
            return;
        }
        double* temp;
        for (int i = 0; i < k;i++){
            temp = arr + i * (size / k);
            kWayMergeSort(temp, size / k, k);
        }
        if (size % k) {
            temp = arr + size - size % k;
            kWayMergeSort(temp, size%k, k);
        }
            
        
        merge(arr, size, k);
	}

}