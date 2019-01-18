#include <stdio.h>

int main(void) {
    int a, b, c, answer;
    scanf("%d %d %d", &a, &b, &c);
    answer = (b-a) > (c-b) ? (b-a) : (c-b);
    printf("%d\n", answer-1);
    return 0;
}
