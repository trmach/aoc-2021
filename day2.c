#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10

int main() {
	/* open file and put lines into an array */
	char *path = "input2.txt";
	char line[MAX_LINE_LENGTH] = {0};
	FILE *file = fopen(path, "r");
	int linecount = 0;
	char a[2000][10] = {"\0"};
	int h = 0, depth = 0, aim = 0;
	
	for (int i = 0; i < 2000; i++) {
		if(fscanf(file, "%s", &a[i])) {
		} else {
			break;
		}
	}
	printf("bitchass\n");

	for(int i = 0; i < 2000; i = i + 2) {
		if(strcmp("forward", a[i]) == 0) {
			h = h + atoi(a[i+1]);
		} else if (strcmp("down", a[i]) == 0) {
			depth = depth + atoi(a[i+1]);
		} else if (strcmp("up", a[i]) == 0) {
			depth = depth - atoi(a[i+1]);
		} else {
			printf("bitchass wait how did this happen\n");
		}
	}

	printf("The answer for part 1 is: %d\n", h * depth);
	depth = 0;
	h = 0;
	for (int i = 0; i < 2000; i = i + 2) {
		if(strcmp("forward", a[i]) == 0) {
			h = h + atoi(a[i+1]);
			depth = depth + (aim * atoi(a[i+1]));
		} else if (strcmp("down", a[i]) == 0) {
			aim = aim + atoi(a[i+1]);
		} else if (strcmp("up", a[i]) == 0) {
			aim = aim - atoi(a[i+1]);
		} else {
			printf("bitchass wait how did this happen\n");
		}
	}

	//printf("%d\n%d\n", h, depth);
	printf("The answer for part 2 is: %d\n", h * depth);
	



	if(fclose(file)) {
		return EXIT_FAILURE;
		perror(path);
	} else {
		return 0;
	}
}
