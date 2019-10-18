#include <stdio.h>

void selectionSort(int data[], int n) {
	int tmp;
	int last = 0;
	for (int i = 0; i < n - 1; i++) {
		last = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[last]) {
				last = j;
			}
		}
		tmp = data[last];
		data[last] = data[i];
		data[i] = tmp;
	}
}

void bubbleSort(int A[], int n) {
	int tmp;
	for (int last = n; last > 0; last--) {
		int stored = 1;
		for (int j = 1; j < last - 1; j++) {
			if (A[j] > A[j +1]) {
				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
				stored = 0;
			}
		}
		if (stored == 1) {
			return 0;
		}
	}
}

void insertionSort(int A[], int n) {
	int loc;
	int check;
	for (int i = 1; i < n; i++) {
		loc = i - 1;
		check = A[i];
		while (loc >= 1 && check < A[loc]) {
			A[loc + 1] = A[loc];
			loc--;
		}
		A[loc + 1] = check;
	}
}


int main() {
	int A[] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	int B[] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	int C[] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	selectionSort(A, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	bubbleSort(B, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");
	insertionSort(C, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", C[i]);
	}
}