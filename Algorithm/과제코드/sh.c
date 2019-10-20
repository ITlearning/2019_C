#include <stdio.h>
#define MAX 100000
int shirt[MAX];
int pri = 0;
int N = 0;

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

void NewClothes(){
	int M = N % 3;
	for (int i = 0; i < N; i++) {
		if (i % 3 == M) {
			continue;
		}
		else {
			pri += shirt[i];
		}
	}
} 



int main() {
	int T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		for (int j = 0; j < N; j++) {
			scanf("%d", &shirt[j]);
		}
		quickSort(shirt, 0, N - 1);
		NewClothes();


		printf("%d \n", pri);
		
		pri = 0;
	}
}