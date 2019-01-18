#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int totalCaseN;
    int stickLen;
    int antsNum;
    int shortest, longest;
    int* ants;
    int i, j;
    int shortT, longT;
    scanf("%d", &totalCaseN);
    for(i=0; i<totalCaseN; i++) {
        scanf("%d %d", &stickLen, &antsNum);
        ants=(int*)malloc(sizeof(int)*antsNum);
        for(j=0; j<antsNum; j++) {
            scanf("%d", &ants[j]);
        }
         if(ants[0]<stickLen-ants[0]) {
            shortest = ants[0];
            longest = stickLen-ants[0];
        } else {
            shortest = stickLen-ants[0];
            longest = ants[0];
        }
        for(j=1; j<antsNum; j++) {
            if(ants[j]<stickLen-ants[j]) {
                shortT = ants[j];
                longT = stickLen-ants[j];
            } else {
                shortT = stickLen-ants[j];
                longT = ants[j];
            }
            shortest = shortest < shortT ? shortT : shortest;
            longest = longest < longT ? longT : longest;
        }
        printf("%d %d\n", shortest, longest);
        free(ants);
    }
    return 0;
}
