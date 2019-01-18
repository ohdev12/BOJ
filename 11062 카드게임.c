#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

int answer(int cards[], int first, int last) {
    if(last-first == 2) {

    }
    max(answer(cards))
    return cards[0];
}

int main(void) {
    int caseN;
    int cardN;
    int* cards;
    int i, j;
    scanf("%d", &caseN);
    for(i=0; i<caseN; i++) {
        scanf("%d", &cardN);
        cards = (int*)malloc(sizeof(int)*cardN);
        for(j=0; j<cardN; j++) scanf("%d", &cards[j]);
        printf("%d\n", answer(cards, 0, cardN-1));
    }
    return 0;
}
