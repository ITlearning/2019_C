#include <stdio.h>
#define MAX_N 15

int weight[MAX_N + 1];
int result = 0;
int N = 0;

void countTeams(int h, int wA, int wB, int wC) {
	if (h == N) {
		result++;
	}
	else {
		countTeams(h + 1, wA + weight[h], wB, wC);
		countTeams(h + 1, wA, wB + weight[h], wC);
		countTeams(h + 1, wA, wB, wC + weight[h]);
		countTeams(h + 1, wA, wB, wC);
	}
}

int main() {
	int T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		for (int j = 1; j <= N; j++) {
			scanf("%d", &weight[j]);
		}
	}
	printf("%d", result);
	result = 0;
}