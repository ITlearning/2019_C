#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void swap(int A[], int a, int b) {
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;

}

int partition(int A[], int p, int r) {

	int mid = (p + r) / 2;
	swap(A, p, mid);

	int pivot = A[p]; //가운데 숫자를 첫번째로 옮긴후 피봇 설정
	int i = p, j = r;

	while (i < j) {
		while (pivot < A[j]) { //A의 뒤쪽 배열이 피봇보다 클 경우까지 가는거
			j--;
		}
		while (i < j && pivot >= A[i]) {
			i++;
		}
		swap(A, i, j);
	}
	A[p] = A[i];
	A[i] = pivot;

	return i;
}


void quickSort(int A[], int p, int r) {
	if (p >= r) {
		return;
	}
	int q = partition(A, p, r);
	quickSort(A, p, q - 1);
	quickSort(A, q + 1, r);

}

int main() {
	int random;
	int mergeInput[100000], quickInput[100000];
	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < 10; i++) {
		random = rand();
		mergeInput[i] = random;
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
		random = rand();
		mergeInput[i] = random;
		quickInput[i] = random;
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

		printf("Merge Sort : %fsec ", result/ CLOCKS_PER_SEC);
		printf(" Quick Sort : %fsec \n", (double)(e - s) / CLOCKS_PER_SEC);

		
	}

}