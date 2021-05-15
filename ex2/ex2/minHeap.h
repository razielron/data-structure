#pragma once
#include <stdio.h>    
#include <stdlib.h> 
using namespace std;

namespace ex2
{
	typedef struct
	{
		double value;
		int kArr;
	}Pair;

	class MinHeap {
	private:
		Pair* _data;
		int _maxSize;
		int _heapSize;
		int _allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void fixHeap(int node);
	
	public:
		MinHeap(int max);
		~MinHeap();
		Pair min() { return _data[0]; }
		Pair deleteMin();
		void insert(Pair item);
		void swap(Pair& a, Pair& b);
	};
}