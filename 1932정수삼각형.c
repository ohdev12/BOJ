#include <stdio.h>
#include <stdlib.h>

int** triangle;
int max(int a, int b) {
    return b > a ? b : a;
}
int main(void) {
    int height;
    int i, j;
    scanf("%d", &height);
    triangle = (int**)malloc(sizeof(int*)*height);
    for(i=0; i<height; i++)
        triangle[i] = (int*)malloc(sizeof(int)*height);
    for(i=0; i<height; i++) {
        for(j=0; j<=i; j++)
            scanf("%d", &triangle[i][j]);
    }
    for(i=height-2; i>=0; i--)
        for(j=0; j<=i; j++)
            triangle[i][j] = triangle[i][j]+max(triangle[i+1][j], triangle[i+1][j+1]);

    printf("%d\n", triangle[0][0]);
    return 0;
}
