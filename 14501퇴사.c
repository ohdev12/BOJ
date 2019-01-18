#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* max;
    int i;
    int days;
    int* howlong;
    int* howmuch;

    scanf("%d", &days);
    howlong = (int*)malloc(sizeof(int)*(days+1));
    howmuch = (int*)malloc(sizeof(int)*(days+1));
    max = (int*)malloc(sizeof(int)*(days+1));
    for(i=1; i<(days+1); i++)
        scanf("%d %d", &howlong[i], &howmuch[i]);

    for(i=days; i>0; i--) {
        if(i+howlong[i]-1 > days) {
            if(i<days) max[i]=max[i+1];
            else max[i]=0;
        } else {
            if(i+howlong[i] <= days)
                max[i] = howmuch[i]+max[i+howlong[i]] >= max[i+1] ? howmuch[i]+max[i+howlong[i]] : max[i+1];
            else if(i<days)
                max[i] = howmuch[i] >= max[i+1] ? howmuch[i] : max[i+1];
            else max[i] = howmuch[i];
        }
    }

    printf("%d\n", max[1]);

    free(howlong);
    free(howmuch);
    free(max);
    return 0;
}
