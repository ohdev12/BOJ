#include <stdio.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int min3(int a, int b, int c) {
    if(a>b) {
        if(b>c) return c;
        else return b;
    } else {
        if(a>c) return c;
        else return a;
    }
}

int main(void) {
    int i;
    int nOfH;
    int* R;
    int* G;
    int* B;
    scanf("%d", &nOfH);
    R = (int*)malloc(sizeof(int)*nOfH);
    G = (int*)malloc(sizeof(int)*nOfH);
    B = (int*)malloc(sizeof(int)*nOfH);
    for(i=0; i<nOfH; i++)
        scanf("%d %d %d", &R[i], &G[i], &B[i]);

    for(i=1; i<nOfH; i++) {
        R[i] += min(G[i-1], B[i-1]);
        G[i] += min(R[i-1], B[i-1]);
        B[i] += min(R[i-1], G[i-1]);
    }
    printf("%d", min3(R[nOfH-1], G[nOfH-1], B[nOfH-1]));
    return 0;
}
