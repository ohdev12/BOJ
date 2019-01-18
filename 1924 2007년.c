#include <stdio.h>

int main(void) {
    int i, m, d, answer=-1;
    char day[7][4] = {{"MON"}, {"TUE"}, {"WED"}, {"THU"}, {"FRI"}, {"SAT"}, {"SUN"}};
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d %d", &m, &d);
    for(i=0; i<(m-1); i++)
        answer += month[i];
    answer += d;
    printf("%s\n", day[answer%7]);
    return 0;
}
