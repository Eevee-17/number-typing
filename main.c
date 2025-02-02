#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randNum;
int typedNum;
int loop;
unsigned int score;

int main() {

	srand(time(NULL));

	score = 0;

	loop = 1;
	while(loop) {
		randNum = rand() % (8 << (rand() % 13)); // I added more randomness to this to vary the size of the numbers more
		printf("%d\n", randNum);

		scanf(" %d", &typedNum);

		if(randNum == typedNum) {
			printf(":)\n\n");

			score++;
		} else {
			printf(":(\n\nScore: %u\n", score);

			loop = 0;
		}
	}

	return 0;
}
