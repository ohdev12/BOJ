#include <stdio.h>
#include <stdlib.h>

short** map;
int** pathnum;
char** end;
int col, row;

void makeItEnd(int a, int b) {
    int m = map[a][b];
    int p = pathnum[a][b];
    if(a>0 && m<map[a-1][b]) {
        if(end[a-1][b]!=1)
            makeItEnd(a-1, b);
        pathnum[a][b] += pathnum[a-1][b];
    };
    if(a<(row-1) && m < map[a+1][b]) {
        if(end[a+1][b]!=1)
            makeItEnd(a+1, b);
        pathnum[a][b] += pathnum[a+1][b];
    };
    if(b>0 && m<map[a][b-1]) {
        if(end[a][b-1]!=1)
            makeItEnd(a, b-1);
        pathnum[a][b] += pathnum[a][b-1];
    };
    if(b<(col-1) && m<map[a][b+1]) {
        if(end[a][b+1]!=1) makeItEnd(a, b+1);
        pathnum[a][b] += pathnum[a][b+1];
    };
    end[a][b]=1;
}

int main(void) {
    int i, j;
    int m, p;
    scanf("%d %d", &row, &col);
    map = (short**)malloc(sizeof(short)*(row));
    pathnum = (int**)malloc(sizeof(int)*(row));
    end = (char**)malloc(sizeof(char)*row);
    for(i=0; i<row; i++) {
        map[i] = (short*)malloc(sizeof(short)*col);
        pathnum[i] = (int*)malloc(sizeof(int)*col);
        end[i] = (char*)malloc(sizeof(char)*col);
        for(j=0; j<col; j++) {
            pathnum[i][j] = 0;
            end[i][j]=0;
        }
    }
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            scanf("%d", &map[i][j]);
    pathnum[0][0]=1;
    end[0][0] = 1;

    // 다 받으면 완성이고! 완성된 것만 받는다.
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++)
            if(end[i][j]!=1)
                makeItEnd(i, j);
    }
    /*
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++)
            printf("%d ", pathnum[i][j]);
        printf("\n");
    }
    */
    printf("%d\n", pathnum[row-1][col-1]);
    free(map);
    free(pathnum);
    return 0;
}
