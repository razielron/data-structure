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
        return num[index - 1];
	}


    void Sort::swap(double* num1, double* num2) {
        double temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }

    double Sort::medianFinder(double*& arr, int n, int size)
        {
            if (n == size/2)
                return arr[n];

            for (int i = 0; i < n - 1; i++)
                if (arr[i] > arr[i + 1])
                    swap(&arr[i], &arr[i + 1]);

            return medianFinder(arr,  n - 1, size);
    }

    void Sort::bubbleSort(double** num, int size) {
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if ((*num)[j] > (*num)[j + 1])
                    swap((*num) + j, (*num) + j + 1);
    }

    double Sort::quintileSort(double** num, int size, int index) {
        int div, bSize, pivot, lastArrMedian=0;
        div = bSize = size / 5;
        int mod = size % 5;
        double* temp;

        if (size <= 5) {
            bubbleSort(num, size);
            return (*num)[index - 1];
        }
        else {
            for (int i = 0; i < div; i++) {
                temp = (*num) + i * 5;
                bubbleSort(&temp, 5);
            }
            if (mod) {
                temp = (*num) + size - mod;
                bubbleSort(&temp, mod);
                bSize++;
            }
        }

        DynamicArr<double> bArr;
        for (int i = 0; i < bSize; i++) {
            if (mod && (i == bSize - 1)) {
                lastArrMedian = ((div) * 5 + ceil((mod) / 2));
                bArr.push_back((*num)[lastArrMedian]);
            }
            else {
                bArr.push_back((*num)[i * 5 + 2]);
            }
        }

        double* copiedArr = new double[size];
        bArr.copy(copiedArr);
        double bMedian = medianFinder(copiedArr, bSize, bSize);
        int medianIndex = bArr.find(bMedian);
        pivot = (medianIndex == (bSize - 1)) ? lastArrMedian : (medianIndex * 5 + 2);
        swap(*num, (*num) + pivot);
        pivot = partition(*num, 0, size - 1);
        if ((index - 1) < pivot) 
            return quintileSort(num, pivot, index);
        if ((index - 1) > pivot) {
            temp = (*num) + pivot + 1;
            return quintileSort(&temp, size - pivot - 1, index - pivot - 1);
        }
        return (*num)[index - 1];
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
        delete[] copiedArr;

        copiedArr = new double[size];
        arr.copy(copiedArr);
        cout << endl << "quintile sort:" << endl;
        cout << "The i number is: " << quintileSort(&copiedArr,size, i) << endl;
        printArr(copiedArr, size);
        delete[] copiedArr;

    }
}
