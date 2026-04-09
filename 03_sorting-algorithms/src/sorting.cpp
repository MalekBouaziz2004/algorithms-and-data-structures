// ADS Praktikum 2.1 Sortieren
// Name: Max Mustermann
#include "sorting.h"
#include <cmath> // pour pow()

namespace sorting {

	//****************
	// InsertionSort *
	//****************
	void InsertionSort(vector<int>& arr, int n)
	{
		for (int i = 1; i < n; i++) {
			int tmp = arr[i]; // Élément à insérer
			int j = i - 1;

			// Décale les éléments plus grands vers la droite
			while (j >= 0 && arr[j] > tmp) {
				arr[j + 1] = arr[j];
				j--;
			}

			// Place l'élément à sa bonne position
			arr[j + 1] = tmp;
		}
	}


	//************
	// QuickSort *
	//************    
	int Partition(vector<int>& A, int p, int r) {
		int x = A[r];       // pivot = dernier élément
		int i = p - 1;      // i sépare éléments <= pivot

		for (int j = p; j <= r - 1; j++) {
			if (A[j] <= x) {
				i++;
				swap(A[i], A[j]);
			}
		}

		swap(A[i + 1], A[r]); // place le pivot à sa position correcte
		return i + 1;
	}

	void QuickSort(vector<int>& arr, int left, int right)
	{
		if (left < right) {
			int q = Partition(arr, left, right);  // partitionner
			QuickSort(arr, left, q - 1);          // trier à gauche
			QuickSort(arr, q + 1, right);         // trier à droite
		}
	}


	//************
	// MergeSort *
	//************
	void Merge(vector<int>& a, vector<int>& b, int low, int pivot, int high)
	{
		int left = low;
		int right = pivot;
		int index = low;

		// Fusionne dans b
		while (left < pivot && right <= high) {
			if (a[left] <= a[right]) {
				b[index++] = a[left++];
			} else {
				b[index++] = a[right++];
			}
		}

		// Copie le reste de la partie gauche
		while (left < pivot) {
			b[index++] = a[left++];
		}

		// Copie le reste de la partie droite
		while (right <= high) {
			b[index++] = a[right++];
		}

		// Copie de b vers a
		for (int i = low; i <= high; i++) {
			a[i] = b[i];
		}
	}

	void MergeSort(vector<int>& a, vector<int>& b, int low, int high)
	{
		if (low < high) {
			int pivot = (low + high) / 2;
			MergeSort(a, b, low, pivot);         // Trie la première moitié
			MergeSort(a, b, pivot + 1, high);    // Trie la deuxième moitié
			Merge(a, b, low, pivot + 1, high);   // Fusionne les deux moitiés
		}
	}


	//************
	// Heapsort  *
	//************
	// Hilfsfunktion: Heapify für Min-Heap
	void heapify(vector<int>& a, int n, int i) {
		int left = 2 * i + 1;  // Linkes Kind
		int right = 2 * i + 2; // Rechtes Kind
		int minIndex = i;

		if (left < n && a[left] < a[minIndex]) {
			minIndex = left;
		}
		if (right < n && a[right] < a[minIndex]) {
			minIndex = right;
		}
		if (minIndex != i) {
			swap(a[i], a[minIndex]);
			heapify(a, n, minIndex);
		}
	}

	// Funktion zum Aufbau des Heaps
	void buildheap(vector<int>& a, int n) {
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(a, n, i);
		}
	}

	// HeapSort Funktion
	void HeapSort(vector<int>& a, int n) {
		buildheap(a, n);
		for (int i = n - 1; i >= 0; i--) {
			swap(a[0], a[i]);
			heapify(a, i, 0);
		}
	}


	//************
	// Shellsort *
	//************

	// Hier soll Hibbard implementiert werden
	void ShellSort_2n(vector<int>& a, int n) {
		int gap = 1;
		while ((gap * 2 + 1) < n) {
			gap = gap * 2 + 1; // Hibbard : 1, 3, 7, 15, ...
		}

		while (gap > 0) {
			for (int i = gap; i < n; i++) {
				int tmp = a[i];
				int j = i;
				while (j >= gap && tmp < a[j - gap]) {
					a[j] = a[j - gap];
					j -= gap;
				}
				a[j] = tmp;
			}
			gap = (gap - 1) / 2;
		}
	}

	// Hier soll 2^i implementiert werden
	void ShellSort_2Square(vector<int>& a, int n) {
		int gap = 1;
		while (gap * 2 < n) {
			gap = gap * 2;
		}

		while (gap > 0) {
			for (int i = gap; i < n; i++) {
				int tmp = a[i];
				int j = i;
				while (j >= gap && tmp < a[j - gap]) {
					a[j] = a[j - gap];
					j -= gap;
				}
				a[j] = tmp;
			}
			gap /= 2;
		}
	}


	//***************
	// CountingSort *
	//***************
	void CountingSort(vector<int>& a, int left, int right) 
		if (left >= right)
			return;

		int M = a[left];
		for (int i = left + 1; i <= right; i++) {
			if (a[i] > M)
				M = a[i];
		}

		vector<int> Count(M + 1, 0);
		for (int i = left; i <= right; i++) {
			Count[a[i]]++;
		}
       //noch eine schritt
		int i = left;
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k < Count[j]; k++) {
				a[i++] = j;
			}
		}
	


	//************
	// RadixSort *
	//************
	int ermittleZiffernlaenge(int daten[], int laenge) {
		int groesstesElement = daten[0];
		for (int i = 1; i < laenge; i++) {
			if (daten[i] > groesstesElement)
				groesstesElement = daten[i];
		}

		int stellen = 0;
		while (groesstesElement > 0) {
			stellen++;
			groesstesElement /= 10;
		}
		return stellen;
	}

	void SortByDigit(vector<int>& A, int left, int right, int k) {
		const int R = 10;
		vector<int> Count(R, 0);
		vector<int> Pos(R, 0);
		int n = right - left + 1;
		vector<int> B(n);

		for (int i = left; i <= right; i++) {
			int j = (A[i] / (int)pow(10, k - 1)) % 10;
			Count[j]++;
		}

		int i = left;
		for (int j = 0; j < R; j++) {
			Pos[j] = i;
			i += Count[j];
		}

		for (int i = left; i <= right; i++) {
			int j = (A[i] / (int)pow(10, k - 1)) % 10;
			B[Pos[j] - left] = A[i];
			Pos[j]++;
		}

		for (int i = left; i <= right; i++) {
			A[i] = B[i - left];
		}
	}

	void RadixSort(vector<int>& arr, int left, int right)
	{
		int n = arr.size();
		int k_max = ermittleZiffernlaenge(arr.data(), n);
		for (int k = 1; k <= k_max; k++) {
			SortByDigit(arr, left, right, k);
		}
	}

	// Random generator
	void randomizeVector(vector<int>& array, int n) {
		array.resize(n);
		for (int i = 0; i < n; i++)
			array[i] = rand() % 1000000;
	}

} // end namespace sorting





