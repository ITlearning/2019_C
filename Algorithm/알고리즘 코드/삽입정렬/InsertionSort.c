#include <stdio.h>

void insertionSort(int data[], int n) {
	int loc;
	int newitem;
	for (int i = 1; i < n; i++) {
		loc = i - 1;
		newitem = data[i];
		while (loc >= 0 && newitem < data[loc]) {
			data[loc + 1] = data[loc];
			loc--;
		}
		data[loc + 1] = newitem;
	}
}

int main() {

	int data[10] = { 8, 31, 48, 73, 3, 65, 20, 29, 11, 15 };

	insertionSort(data, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
}