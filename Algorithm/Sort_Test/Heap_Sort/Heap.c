#include <stdio.h>

void heapify(int* arr, int size, int mid) {
	int parent_node = mid; // parent node index
	int left_node = parent_node * 2 + 1; // left child node index
	int right_node = parent_node * 2 + 2; // right child node index
	int largest_node = parent_node;
	int temp;

	// Check if left child exists && compare the value
	if (left_node < size && arr[left_node] > arr[largest_node]) {
		largest_node = left_node;
	}
	// Check if right child exists && compare the value
	if (right_node < size && arr[right_node] > arr[largest_node]) {
		largest_node = right_node;
	}
	// Swap
	if (parent_node != largest_node) {
		temp = arr[largest_node];
		arr[largest_node] = arr[parent_node];
		arr[parent_node] = temp;
		// if swap happened then heapify again
		heapify(arr, size, largest_node);
	}


}

// build heap heap tree
void buildMaxHeap(int* arr, int size)
{
	// start from middle node (index starting from 0)
	int mid = size / 2 - 1;

	// loop until root node 
	for (mid; mid >= 0; mid--) {
		heapify(arr, size, mid);
	}
}

/*
Heapsort Algorithm
1. Build heap tree (max, min)
2. Sort by reconstructing the 1. heap tree
*/
void heapSort(int* arr, int size)
{
	buildMaxHeap(arr, size);

	// Swap root node with last node
	// loop until the heap tree size goes to 1
	int temp;
	while (size > 1) {
		temp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = temp;

		size--;
		heapify(arr, size, 0);
	}

}

int main() {
	int A[6] = { 3,6,4,7,8,5 };
	heapSort(A, 6);
	for (int i = 0; i < 6; i++) {
		printf("%d ", A[i]);
	}
}