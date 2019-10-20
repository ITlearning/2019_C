#include <stdio.h>

#define MAX_SIZE 100000
int tmp[MAX_SIZE];

void merge(int A[], int p, int q, int r) {
	int i = p; int j = q + 1; int t = p; int l;
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
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}



int main() {
	int data[10] = { 31, 3, 65, 73, 8, 11, 20, 29, 48, 15 };

	mergeSort(data, 0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
}