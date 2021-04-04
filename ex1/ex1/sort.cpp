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

    void Sort::bubbleSort(double** num, int size) {
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if ((*num)[j] > (*num)[j + 1])
                    swap((*num) + j, (*num) + j + 1);
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

    double Sort::medianFinder(double*& arr, int n, int size)
    {
        if (n == size / 2)
            return arr[n];

        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                swap(&arr[i], &arr[i + 1]);

        return medianFinder(arr, n - 1, size);
    }

    void Sort::swap(double* num1, double* num2) {
        double temp = *num1;
        *num1 = *num2;
        *num2 = temp;
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
        double result;

        //INSERSION SORT
        double* copiedArr = new double[size];
        arr.copy(copiedArr);

        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        result = insertionSort(copiedArr, size, i);
        cout << "Insertion sort i'th element: " << fixed << setprecision(4) << result  << endl;

        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        ofstream myfile("Measure.txt", ios::app);
        myfile << "Time taken by function insertionSort is : " << fixed << time_taken << setprecision(9);
        myfile << " sec" << endl;

        //printArr(copiedArr, size);
        delete[] copiedArr;

        //SELECTION SORT
        copiedArr = new double[size];
        arr.copy(copiedArr);

        start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        result = selectionSort(copiedArr, 0, size - 1, i);
        cout << "Selection i'th element: " << fixed << setprecision(4) << result << endl;

        end = chrono::high_resolution_clock::now();
        time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        myfile << "Time taken by function selectionSort is : " << fixed << time_taken << setprecision(9);
        myfile << " sec" << endl;

        //printArr(copiedArr, size);
        delete[] copiedArr;

        //FIVES SORT
        copiedArr = new double[size];
        arr.copy(copiedArr);

        start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        result = quintileSort(&copiedArr, size, i);
        cout << "Quintuplet algorithm i'th element: " << fixed << setprecision(4) << result << endl;

        end = chrono::high_resolution_clock::now();
        time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        myfile << "Time taken by function quintileSort is : " << fixed << time_taken << setprecision(9);
        myfile << " sec" << endl << endl;
        myfile.close();

        //printArr(copiedArr, size);
        delete[] copiedArr;
    }
}
