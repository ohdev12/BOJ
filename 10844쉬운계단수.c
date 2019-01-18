#include <stdio.h>
#include <stdlib.h>

int** level;
void count(int height) {
    int num;
    if(level[height][0]!=-1)return;
    if(level[height-1][0]==-1) count(height-1);
    for(num=0; num<10; num++) {
        if(num==0) level[height][num] = level[height-1][num+1];
        else if(num==9) level[height][num] = level[height-1][num-1];
        else level[height][num] = level[height-1][num-1] + level[height-1][num+1];

        if(level[height][num]>1000000000) level[height][num]=level[height][num]%1000000000;
    }
}

int main(void) {
    int i, j;
    int length;
    int answer=0;
    scanf("%d", &length);
    level = (int**)malloc(sizeof(int*)*length);
    for(i=0; i<length; i++) {
        level[i] = (int*)malloc(sizeof(int)*10);
        for(j=0; j<10; j++)
            level[i][j] = -1;
    }
    for(i=0; i<10; i++)
        level[0][i] = 1;
    count(length-1);
    for(i=1; i<10; i++) {
        answer+=level[length-1][i];
        if(answer>1000000000) answer = answer%(1000000000);
    }
    printf("answer:%d\n", answer);
    printf("%d\n", level[length-2][0]);
    printf("%d\n", level[length-2][2]);
    printf("%d\n", level[length-1][1]);
    return 0;
}
