#include <stdio.h>

void selectionSort(int data[] ,int n) {
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

void bubbleSort(int data[], int n) {
	int tmp;
	for (int last = n; last > 0; last--) {
		int sorted = 1;
		for (int i = 1; i < last - 1; i++) {
			if (data[i] > data[i + 1]) {
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
				sorted = 0;
			}
		}
		if (sorted == 1) {
			return 0;
		}
	}
}


void insertionSort(int data[], int n) {
	int loc;
	int newitem;
	for (int i = 1; i < n; i++) {
		loc = i - 1;
		newitem = data[i];
		while (loc >= 1 && newitem < data[loc]) {
			data[loc + 1] = data[loc];
			loc--;
		}
		data[loc + 1] = newitem;
	}
}



int main() {
	int data[10] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	int data2[10] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	int data3[10] = { 3, 31, 48, 73, 8, 11, 20, 29, 65, 15 };
	printf("selectionSort \n");
	selectionSort(data, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	printf("bubbleSort \n");
	bubbleSort(data2, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", data2[i]);
	}
	printf("\n");
	printf("selectionSort \n");
	selectionSort(data3, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", data3[i]);
	}
}