#ifndef _SORTING_H_
#define _SORTING_H_

#include <vector>
#include <iostream>
#include <string>

using namespace std;

namespace sorting {
  
	//****************
	// InsertionSort *
	//****************
	void InsertionSort(vector<int>& arr, int n);

	//************
	// QuickSort *
	//************
	void QuickSort(vector<int> &arr, int left, int right);

	//************
	// MergeSort *
	//************
	void Merge(vector<int> &a, vector<int> &b,int low, int pivot, int high);
	void MergeSort(vector<int> &a, vector<int> &b, int low, int high);

	//************
	// Heapsort  *
	//************
	void HeapSort(vector<int> &a, int n);

	//************
	// Shellsort *
	//************
	void ShellSort_2n(vector<int> &a, int n);
	void ShellSort_2Square(vector<int>& a, int n);

	//***************
	// CountingSort *
	//***************
	void CountingSort(vector<int>& arr, int left, int right);

	//************
	// RadixSort *
	//************
	void RadixSort(vector<int>& arr, int left, int right);


	//*******************
	// Helper functions *
	//*******************
	void randomizeVector(vector<int> &array, int n);
  
 }
#endif 
