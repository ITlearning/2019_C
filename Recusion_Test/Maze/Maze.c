#include <stdio.h>

#define PATH		0
#define WALL		1
#define VISITED		2
#define UNAVAILABLE	3
#define N			8

int maze[][8] = { {0, 0, 0, 0, 0, 0, 0, 1},
				  {0, 1, 1, 1, 0, 1, 0, 1},
				  {0, 0, 0, 0, 1, 0, 0, 1},
				  {0, 1, 0, 0, 1, 1, 0, 1},
				  {0, 1, 1, 1, 0, 0, 1, 1},
				  {0, 0, 0, 0, 0, 1, 0, 1},
				  {1, 0, 1, 0, 1, 1, 0, 1},
				  {1, 1, 1, 0, 0, 0, 0, 0} };

void printMaze() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", maze[i][j]);
			printf("\n");
	}
}

int findPath(int x, int y) {
	if (x == N - 1 && y == N - 1) {
		maze[x][y] = VISITED;
		return 1;
	}

	if (maze[x][y] == WALL || maze[x][y] == VISITED)
		return 0;
	if (x < 0 || x >= N || y < 0 || y >= N)
		return 0;

	maze[x][y] = VISITED;
	if(findPath(x - 1, y) || findPath(x, y + 1) || findPath(x + 1, y) || findPath(x, y -1))
		return 1;

	maze[x][y] = UNAVAILABLE;
	return 0;

}

int main() {
	printMaze();
	printf("%d\n", findPath(0, 0));
	printMaze();
}