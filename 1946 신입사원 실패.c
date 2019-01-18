#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int totalCaseN;
    int numOfP;
    int** scores;
    char* isPossible;
    int comp;
    int count;
    int i, j, k;
    scanf("%d", &totalCaseN);
    for(i=0; i<totalCaseN; i++) {
        count = 0;
        scanf("%d", &numOfP);
        scores = (int**)malloc(sizeof(int*)*numOfP);
        isPossible = (char*)malloc(sizeof(char)*numOfP);
        for(j=0; j<numOfP; j++) {
            scores[j] = (int*)malloc(sizeof(int)*2);
            scanf("%d %d", &scores[j][0], &scores[j][1]);
            isPossible[j] = 1;
        }
        for(j=0; j<numOfP; j++) {
            for(k=j+1; k<numOfP; k++) {
                int comp=0;
                if(scores[j][0] < scores[k][0]) comp++;
                if(scores[j][1] < scores[k][1]) comp++;
                switch(comp) {
                case 0:
                    isPossible[j]=0;
                    break;
                case 2:
                    isPossible[k]=0;
                }
            }
            if(isPossible[j]==1) count++;
        }
        for(j=0; j<numOfP; j++) free(scores[j]);
        free(scores);
        free(isPossible);
        printf("%d\n", count);
    }
    return 0;
}
