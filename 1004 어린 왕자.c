#include <stdio.h>

int main(void) {
    char inclPoint[50];
    int caseN;
    int departX, departY, destX, destY;
    int circleN;
    int i;
    int x, y, r;
    int answer;
    scanf("%d", &caseN);
    while(caseN--) {
        answer = 0;
        scanf("%d %d %d %d", &departX, &departY, &destX, &destY);
        scanf("%d", &circleN);
        for(i=0; i<circleN; i++) {
            inclPoint[i]=0;
            scanf("%d %d %d", &x, &y, &r);

            if(((departX-x)*(departX-x)+(departY-y)*(departY-y))<(r*r))
                inclPoint[i]++;
            if(((destX-x)*(destX-x)+(destY-y)*(destY-y))<(r*r))
                inclPoint[i]++;
        }
        for(i=0; i<circleN; i++)
            if(inclPoint[i]==1) answer++;
        printf("%d\n", answer);
    }
    return 0;
}
