#include <stdio.h>
#include <stdlib.h>

int findmax3(int a, int b, int c) {
	int max = a;
	max = max > b ? max : b;
	max = max > c ? max : c;
	return max;
}
int findmax2(int a, int b) {
	return a > b ? a : b;
}
/*
int main(void) {
	int num_stairs, i;
	int* stairs;
	int* max;
	scanf("%d", &num_stairs);
	stairs = (int*)malloc(sizeof(int)*num_stairs);
	max = (int*)malloc(sizeof(int)*num_stairs);
	for (i = 0; i<num_stairs; i++)
		scanf("%d", &stairs[i]);
	if (num_stairs >= 3) {
		max[num_stairs - 1] = stairs[num_stairs - 1];
		max[num_stairs - 2] = stairs[num_stairs - 1] + stairs[num_stairs - 2];
		max[num_stairs - 3] = stairs[num_stairs - 3] + stairs[num_stairs - 1];
		for (i = num_stairs - 4; i >= 0; i--)
			max[i] = findmax3(stairs[i] + stairs[i + 1] + max[i + 3], stairs[i] + max[i + 2], max[i + 1]);
	}
	else if (num_stairs == 1) {
		max[0] = stairs[0];
	}
	else if (num_stairs == 2) {
		max[0] = stairs[0] + stairs[1];
	}
	printf("%d\n", max[0]);
	free(stairs);
	free(max);
	return 0;
}
*/