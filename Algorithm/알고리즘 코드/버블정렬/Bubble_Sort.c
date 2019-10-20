#include <stdio.h>

void bubbleSort(int data[], int n) {
	int tmp;
	int last;
	for (last = n; last > 0; last--) {
		for (int i = 0; i < last - 1; i++) {
			if (data[i] > data[i + 1]) {
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}

int main() {

	int data[10] = { 8, 31, 48, 73, 3, 65, 20, 29, 11, 15 };

	bubbleSort(data, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
}