#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10

int main() {
	char *path = "input1.txt";
	char line[MAX_LINE_LENGTH] = {0};
	FILE *file = fopen(path, "r");
	int inc = 0, dec = 0, suminc = 0, sumdec = 0, linecount = 0;
	printf("bitchass\n");

	int a[2000] = {0};
	
	while (fgets(line, MAX_LINE_LENGTH, file)) {
		a[linecount] = atoi(line);
		linecount = linecount + 1;
	}

	for (int i = 3; i < 2000; i = i + 1) {
		//printf("%d\n", a[i]);
// what a shitshow I didn't even preserve part one		
		if(a[i-3] + a[i-2] + a[i-1] < a[i-2] + a[i-1] + a[i]) {
			suminc = suminc + 1;
		}
	}
	printf("%d\n", suminc);



	if(fclose(file)) {
		return EXIT_FAILURE;
		perror(path);
	}
}
