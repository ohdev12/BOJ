#include <stdio.h>
#include <stdlib.h>

int findmax4(int a, int b, int c, int d) {
    int temp1 = a > b ? a : b;
    int temp2 = c > d ? c : d;
    return temp1 > temp2 ? temp1 : temp2;
}

int findmax3(int a, int b, int c) {
    int max = a;
    max = max > b ? max : b;
    max = max > c ? max : c;
    return max;
}

int main(void) {
    int N, i;
    int* amount;
    int* max;
    scanf("%d", &N);
    amount = (int*)malloc(sizeof(int)*N);
    max = (int*)malloc(sizeof(int)*N);
    for(i=0; i<N; i++)
        scanf("%d", &amount[i]);
    if(N>0) max[0] = amount[0];
    if(N>1) max[1] = amount[0]+amount[1];
    if(N>2) max[2] = findmax3((amount[2]+amount[1]), (amount[1]+amount[0]), (amount[2]+amount[0]));
    if(N>3) max[3] = findmax3((amount[3]+amount[2]+amount[0]), (amount[3]+amount[1]+amount[0]), (amount[2]+amount[1]));
    for(i=4; i<N; i++) {
        max[i] = findmax4((amount[i]+amount[i-1]+max[i-3]), (amount[i]+max[i-2]), (amount[i-1]+amount[i-2]+max[i-4]), (amount[i-1]+max[i-3]));
    }
    printf("%d\n", max[N-1]);
    free(amount);
    free(max);
    return 0;
}
