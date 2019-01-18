#include <stdio.h>
#include <stdlib.h>

typedef struct dot {
    int a;
    int b;
}dot;

int meetornot(int a, int b, int c, int d) { // return 0 if meet, return 1 if don't meet
    int g, l;
    if(a>b) {g=a; l=b;}
    else {g=b; l=a;}
    return ((c>l&&c<g&&d>l&&d<g) || (c<(l+100)&&c>g&&d<(1+100)&&d>g));
}

int main(void) {
    int N, i, j;
    dot* dots;
    int** notmeet;
    int** already;
    int max=0;
    int count=0;
    scanf("%d", &N);
    dots = (dot*)malloc(sizeof(dot)*N);
    notmeet = (int**)malloc(sizeof(int*)*N);
    already = (int**)malloc(sizeof(int*)*N);
    for(i=0; i<N; i++) {
        notmeet[i] = (int*)malloc(sizeof(int)*N);
        already[i] = (int*)malloc(sizeof(int)*N);
        for(j=0; j<N; j++) {
            notmeet[i][j] = 0;
            already[i][j] = 0;
        }
    }
    for(i=0; i<N; i++)
        scanf("%d %d", &(dots[i].a), &(dots[i].b));
    for(i=0; i<N; i++) {
        for(j=i+1; j<N; j++)
            notmeet[i][j] = (meetornot(dots[i].a, dots[i].b, dots[j].a, dots[j].b));
    }
    for(i=0; i<N; i++) {
        for(j=i+1; j<N; j++) {
            if(notmeet[i][j]==1 )
        }
    }
    return 0;
}
