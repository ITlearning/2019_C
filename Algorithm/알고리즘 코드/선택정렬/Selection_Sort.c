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

int main() {
	int data[10] = { 8, 31, 48, 73, 3, 65, 20, 29, 11, 15 };

	selectionSort(data, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	
}