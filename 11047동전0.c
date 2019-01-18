#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* coins;
    int tnumC, amount, i;
    int answer=0;
    scanf("%d %d", &tnumC, &amount);
    coins = (int*)malloc(sizeof(int)*tnumC);
    for(i=0; i<tnumC; i++) {
        scanf("%d", &coins[i]);
    }
    for(i=tnumC-1; i>=0; i--) {
        if(amount>=coins[i]) {
            answer+=amount/coins[i];
            amount%=coins[i];
        }
        if(amount==0) break;
    }
    printf("%d\n", answer);
    free(coins);
    return 0;
}
