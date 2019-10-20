#include <stdio.h>


void move(int start, int target) {

	printf("\nMove from %d to %d", start, target);
}

void hanoi(int n, int start, int work, int target) {
	if (n == 1) {
		move(start, target);
	}
	else {
		hanoi(n - 1, start, target, work);
		move(start, target);
		hanoi(n - 1, work, start, target);
	}
}

int main(void) {
	int i = 5;

	hanoi(i, 1, 2, 3);

	return 0;
}