#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randNum;
int calcNum;
int typedNum;
int mainLoop;
int subLoop;
int choice;
unsigned int score;

int num() {

	subLoop = 1;
	while(subLoop) {
		randNum = rand() % (8 << (rand() % 13)); // I added more randomness to this to vary the size of the numbers more
		printf("\n%d\n", randNum);

		scanf(" %d", &typedNum);

		if(randNum == typedNum) {
			printf(":)\n");

			score++;
		} else {
			printf(":(\n\nScore: %u\n", score);

			subLoop = 0;
		}
	}

	return 0;
}

int hexMath() {
	
	printf("\nMath Options:\n0 - Quit\n1 - All\n2 - Addition\n3 - Subtraction\n4 - Multiplication\n5 - Division\n");
	scanf(" %d", &choice);
	
	subLoop = 0;
	if(choice) {
		subLoop = 1;
	}

	while(subLoop) {
		calcNum = rand() % 256;
		printf("0x%x ", calcNum);
		
		randNum = rand() % 256;

		typedNum = 0; // using typedNum as a temparary storage to hold if choice is set to all
		if(choice == 1) {
			typedNum = 1;
			choice = rand() % 4 + 2;
		}

		switch(choice) {
			case 2:
				printf("+");
				calcNum += randNum;
				break;
			case 3:
				printf("-");
				calcNum -= randNum;
				break;
			case 4:
				printf("*");
				calcNum *= randNum;
				break;
			case 5:
				printf("/");
				calcNum /= randNum;
				break;
		}

		if(typedNum) { // used typedNum as a temparary storage to hold if choice is set to all
			choice = 1;
		}
		
		printf(" 0x%x\n0x", randNum);

		scanf(" %x", &typedNum);

		if(calcNum == typedNum) {
			printf(":)\n\n");

			score++;
		} else {
			printf(":(\nThe answer is 0x%x\n\nScore: %u\n", calcNum,  score);

			subLoop = 0;
		}
	}

	return 0;
}

int main() {
	
	srand(time(NULL));

	mainLoop = 1;
	while(mainLoop) {
		score = 0;

		printf("\n0 - Quit\n1 - Numbers\n2 - Hex Math\n");
		scanf(" %d", &choice);
		
		switch(choice) {
			case 0:
				mainLoop = 0;
				break;
			case 1:
				num();
				break;
			case 2:
				hexMath();
				break;
		}
	}
	return 0;
}
