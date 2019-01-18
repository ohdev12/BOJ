#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a)>(b)) ? (a) : (b))
/*
int main(void) {
	int numOfS;
	int** accuScore;
	int* scores;
	int i, j;
	scanf("%d", &numOfS);
	accuScore = (int**)malloc(sizeof(int*)*numOfS);
	scores = (int*)malloc(sizeof(int)*numOfS);
	for (i = 0; i<numOfS; i++) {
		scanf("%d", &scores[i]);
		accuScore[i] = (int*)malloc(sizeof(int) * 2);
	}
	accuScore[0][0] = scores[0];
	accuScore[0][1] = -1;
	if (numOfS > 1) {
		accuScore[1][0] = scores[1];
		accuScore[1][1] = scores[0] + scores[1];
		for (i = 2; i < numOfS; i++) {
			accuScore[i][0] = scores[i] + max(accuScore[i - 2][0], accuScore[i - 2][1]);
			accuScore[i][1] = scores[i] + accuScore[i - 1][0];
		}
	}
	printf("%d\n", max(accuScore[numOfS - 1][0], accuScore[numOfS - 1][1]));
	for (i = 0; i<numOfS; i++) free(accuScore[i]);
	free(accuScore);
	free(scores);

	return 0;
}
*/