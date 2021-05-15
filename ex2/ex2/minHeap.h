#pragma once
#include <stdio.h>    
#include <stdlib.h> 
using namespace std;

namespace ex2
{
	class MinHeap {
	private:
		double* _data;
		int _maxSize;
		int _heapSize;
		int _allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void fixHeap(int node);
	
	public:
		MinHeap(int max);
		MinHeap(double a[], int n);
		~MinHeap();
		double min();
		double deleteMin();
		void insert(double item);
		void swap(double& a, double& b);
	};
}