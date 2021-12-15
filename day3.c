#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LINE_COUNT 12
#define MAX_LINE_LENGTH 6
#define INPUT_PATH "sample3.txt"

int main() {
	/* open file and put lines into an array */
	char *path = INPUT_PATH;
	char line[MAX_LINE_LENGTH] = {0};
	FILE *file = fopen(path, "r");
	//int linecount = LINE_COUNT;
	char a[LINE_COUNT][MAX_LINE_LENGTH] = {"\0"};
	//char gamma[MAX_LINE_LENGTH] = {"\0"};
	//char epsilon[MAX_LINE_LENGTH] = {"\0"};
	double gamma = 0, epsilon = 0;
	// what a fucken mess
	char c = *"\0";
	for (int i = 0; i < LINE_COUNT; i++) {
		for (int j = 0; j < MAX_LINE_LENGTH; j++) {
			fscanf(file, "%c", &c);
			if(c == *"\n") {
				break;
			} else {
				a[i][j] = c;
			}

		}	
	}
	
	printf("%s\n", &a[0][0]);
	printf("%c\n", a[0][1]);
	printf("%c\n", a[0][2]);

	
	printf("bitchass\n");
//	printf("%s\n", &a[0][0]);

	int count0 = 0, count1 = 0;
	for (int j = 0; j < MAX_LINE_LENGTH; j++) {
		for (int i = 0; i < LINE_COUNT; i++) {
			//printf("%c", a[i][j]);
			if (a[i][j] == *"1") {
				count1++;
			} else if (a[i][j] == *"0") {
				count0++;
			} else {}
		}
		if (count0 > count1) { // least common bit is 1 so 2^j gets added to epsilon
			//gamma[j] = "0";
			epsilon = epsilon + pow(2, MAX_LINE_LENGTH - j - 2);
		} else if (count0 < count1) { //most common bit is 1 so 2^j gets added to gamma
			//gamma[j] = "1";
			gamma = gamma + pow(2, MAX_LINE_LENGTH - j - 2);
		} else {}
		count0 = 0;
		count1 = 0;
	}
	
	printf("Gamma: %f\nEpsilon: %f\nProduct: %f\n", gamma, epsilon, gamma * epsilon);

	int zero_idx[LINE_COUNT] = {0};
	int one_idx[LINE_COUNT] = {0};
	char b[LINE_COUNT][MAX_LINE_LENGTH] = {"\0"};
	for (int why = 0; why < count1 + count0; why++) {
		for (int j = 0; j < MAX_LINE_LENGTH; j++) {
			for (int i = 0; i < LINE_COUNT; i++) {
				if (a[i][j] == *"1") {
					one_idx[count1] = i;
					printf("one %d\n", count1);
					count1++;
				} else if (a[i][j] == *"0") {
					zero_idx[count0] = i;
					printf("zero %d\n", count0);
					count0++;
				} else {}
			}
			if (count0 > count1) { // zero more common
				printf("bitchass zero\n");
				for(int k = 0; k < count0; k++) {
					if(a[zero_idx[count0]][j] == 0) { // if char in column j is zero
						printf("char in column %d is zero", j);
						for (int n = 0; n < MAX_LINE_LENGTH; n++) {
							b[j][n] = a[zero_idx[count0]][n]; // keep the whole string and store in b
						}
					}
				}
			} else if (count0 < count1) { // one more common
				printf("bitchass one\n");
				for(int k = 0; k < count1; k++) {
					if(a[one_idx[count1]][j] == 1) { // if char in column j is one
						printf("char in column %d is one", j);
						for (int n = 0; n < MAX_LINE_LENGTH; n++) {
							b[j][n] = a[zero_idx[count1]][n]; // keep the whole string and store in b
						}
					}
				}
			} else {}
			
			printf("%c", b[0][j]);
			count0 = 0;
			count1 = 0;
		}
		for (int i = 0; i < count0 + count1; i++) {
			for (int k = 0; k < MAX_LINE_LENGTH; k++) {
				a[i][k] = b[i][k]; // copy b to a
				//printf("bitchass copying %d \n", count1 * k);
			}
		}
	}


	if(fclose(file)) {
		return EXIT_FAILURE;
		perror(path);
	} else {
		return 0;
	}
}
