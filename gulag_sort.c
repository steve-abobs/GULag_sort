#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define UP true
#define DOWN false

typedef struct {

	int size;
	int *content;
} Array;

void printrr(Array arr) {

	/* Function prints array */

	for (int i = 0; i < arr.size; i++) {
	
		printf("%d ", arr.content[i]);
	}

	printf("\n");
}

Array gulagSort(int argc, char *argv[], bool up) {

	/* All numbers that break the order are sent to GULag.
	 * UP = ascending order */

	Array arr;

	arr.size = 0;
	arr.content = malloc(argc * sizeof(int));

	for (int i = 1; i < argc; i++) {
	
		int num = atoi(argv[i]);

		if (i == 1) {
		
			arr.content[arr.size++] = num;
			continue;
		} 

		if (num >= arr.content[arr.size - 1] && up) {
		
			arr.content[arr.size++] = num;
		}


		if (num <= arr.content[arr.size - 1] && !up) {
		
			arr.content[arr.size++] = num;
		}
	}

	return arr;
}

int main(int argc, char *argv[]) {

	Array arr = gulagSort(argc, argv, UP);

	printrr(arr);

	free(arr.content);

	return 0;
}
