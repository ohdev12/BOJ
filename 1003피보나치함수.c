#include <stdio.h>
#include <stdlib.h>

// ���� N���� �� �޾Ƽ� �迭�� ������ �Ѵ�. �׸���� �� ���� �߿��� ���� ū ���� �������� count�Լ��� �� �� ȣ���ؼ� �� �� ������ ������� �� �������´�.
// �� ������ �������� ���� ����.
int** howmany;

int findMax(short* array, int idx) {
    int max = array[0];
    int i;
    for(i=1; i<idx; i++)
        max = (max < array[i]) ? array[i] : max;
    return max;
}

void count(int n) {
    if(howmany[n][0]==-1){
        if(howmany[n-2][0]==-1)
            count(n-2);
        if(howmany[n-1][0]==-1)
            count(n-1);
        howmany[n][0] = howmany[n-1][0] + howmany[n-2][0];
        howmany[n][1] = howmany[n-1][1] + howmany[n-2][1];
    } else return;
}

int main(void) {
    int i, cases;
    int num_case, N;
    short* caseNums;
    int max;
    scanf("%d", &num_case);
    caseNums = (short*)malloc(sizeof(short)*num_case);
    for(cases=0; cases<num_case; cases++) {
        scanf("%d", &N);
        caseNums[cases] = N;
    }
    max = findMax(caseNums, num_case);
    howmany = (int**)malloc(sizeof(int*)*(max+1));
    for(i=0; i<(max+1); i++) {
        howmany[i] = (int*)malloc(sizeof(int)*2);
        howmany[i][0] = -1;
        howmany[i][1] = -1;
    }
    howmany[0][0] = 1;
    howmany[0][1] = 0;
    howmany[1][0] = 0;
    howmany[1][1] = 1;
    count(max);
    for(i=0; i<num_case; i++){
        printf("%d %d\n", howmany[caseNums[i]][0], howmany[caseNums[i]][1]);
    }
}
