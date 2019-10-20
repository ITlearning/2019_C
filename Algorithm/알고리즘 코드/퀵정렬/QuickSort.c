#include <stdio.h>

void swap(int data[],int a, int b) {
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

int partition(int data[], int p, int r) {
	int mid = (p + r) / 2;
	swap(data, p, mid);

	int pivot = data[p];
	int i = p; int j = r;
	while (i < j) {
		while (pivot < data[j]) {
			j--;
		}
		while (i < j && pivot >= data[i]) {
			i++;
		}
		swap(data, i, j);
	}
	data[p] = data[i];
	data[i] = pivot;

	return i;
}

void quickSort(int data[], int p, int r) {
	if (p >= r) {
		return;
	}
	int q = partition(data, p, r);
	quickSort(data, p, q - 1);
	quickSort(data, q + 1, r);
}

int main() {

	int data[10] = { 31, 3, 65, 73, 8, 11, 20, 29, 48, 15 };

	quickSort(data, 0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
}