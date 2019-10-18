#include <stdio.h>
#define BACKGROUND_PIXEL 0
#define IMAGE_PIXEL 1
#define COUNTED 2


int cells[][8] = {

  {0,0,1,0,0,0,0,1},
  {1,1,0,0,0,1,0,0},
  {0,0,1,0,1,0,1,0},
  {0,0,0,0,0,1,0,0},
  {0,1,0,1,0,1,0,0},
  {0,1,0,1,0,1,0,0},
  {1,0,0,0,1,1,0,0},
  {0,1,1,0,0,0,1,1}
};

int countCells(int x, int y) {

	int count = 0;

	if (cells[x][y] == BACKGROUND_PIXEL) {
		return 0;
	}
	else if (cells[x][y] == COUNTED) {
		return 0;
	}
	else if ((0 > x || x > 7) || (0 > y || y > 7)) {
		return 0;
	}

	cells[x][y]++;
	count++;

	count = count + countCells(x + 1, y);
	count = count + countCells(x - 1, y);
	count = count + countCells(x, y + 1);
	count = count + countCells(x, y - 1);
	count = count + countCells(x + 1, y + 1);
	count = count + countCells(x + 1, y - 1);
	count = count + countCells(x - 1, y + 1);
	count = count + countCells(x - 1, y - 1);

	return count;

}

int main() {

	printf("%d\n", countCells(3, 5));

}