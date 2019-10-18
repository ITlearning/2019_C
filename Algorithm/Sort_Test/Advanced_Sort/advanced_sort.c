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

void swap(int A[], int a, int b) {
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;

}

int partition(int A[], int p, int r) {
	int mid = (p + r) / 2;
	swap(A, p, mid); //중간에 있는 수를 제일 왼쪽에 옮김

	int pivot = A[p]; //옮긴 숫자를 피봇으로 설정
	int i = p, j = r; //i, j 설정

	while (i < j) {
		while (A[j] > pivot) {
			j--;
		}
		while (i < j && A[i] <= pivot) {
			i++;
		}
		swap(A, i, j);
	}
	A[p] = A[i];
	A[i] = pivot;
	
}

void quickSort(int A[], int p, int r) {
	if (p >= r) {
		return;
	}
	else {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main() {
	int mergeInput[100000],quickInput[100000];
	int num;
	rand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		num = rand();
		mergeInput[i] = num;
		quickInput[i] = mergeInput[i];
	}
	mergeSort(mergeInput, 0, 9);
	quickSort(quickInput, 0, 9);
	printf("Merge Sort : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", mergeInput[i]);
	}
	printf("\n");
	printf("Quick Sort : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", quickInput[i]);
	}

	printf("\n");

	for (int i = 0; i < 100000; i++) {
		num = rand();
		mergeInput[i] = num;
		quickInput[i] = num;
	}

	clock_t start1 = 0, end1 = 0;

	for (int i = 0; i < 5; i++) {


		clock_t start = clock();

		mergeSort(mergeInput, 0, 99999);

		clock_t end = clock();

		double result = (double)(end - start);

		clock_t s = clock();

		quickSort(quickInput, 0, 99999);

		clock_t e = clock();

		printf("Merge Sort : %fsec ", result / CLOCKS_PER_SEC);
		printf(" Quick Sort : %fsec \n", (double)(e - s) / CLOCKS_PER_SEC);


	}
	
}