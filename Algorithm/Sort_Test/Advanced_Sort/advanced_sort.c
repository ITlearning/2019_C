#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
int tmp[MAX];
void merge(int A[], int p, int q, int r) {
	int i = p,j = q +1, t = p, l;
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) {
			tmp[t++] = A[i++];
		}
		else {
			tmp[t++] = A[j++];
		}
	}

	if (i > q) {
		for (l = j; l <= r; l++) {
			tmp[t++] = A[l];
		}
	}
	else {
		for (l = i; l <= q; l++) {
			tmp[t++] = A[l];
		}
	}

	for (l = p; l <= r; l++) {
		A[l] = tmp[l];
	}
}

void mergeSort(int A[], int p, int r) {
	if (p < r) {
		int mid = (p + r) / 2;
		mergeSort(A, p, mid);
		mergeSort(A, mid + 1, r);
		merge(A, p, mid, r);
	}
}

int partition(int A[], int p, int r) {
	int pivot = A[(p + r) / 2];
	int j = pivot + 1;
	int tmp;
	for (int i = p; i < r; i++) {
		if (A[i] < pivot) {
			tmp = 
		}
	}
}

void quickSort(int A[], int p, int r) {
	if (p < r) {
		int pivot = partition(A, p, r);

	}
}

int main() {
	int mergeInput[10];
	int num;
	rand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		num = rand();
		mergeInput[i] = num;
	}

	mergeSort(mergeInput, 0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", mergeInput[i]);
	}
	
}