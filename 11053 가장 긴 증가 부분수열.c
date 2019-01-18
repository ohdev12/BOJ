#include <stdio.h>

int main(void) {
    int seqLen;
    int seq[1000];
    int accum[1000];
    int i, j;
    int max=0;
    scanf("%d", &seqLen);
    for(i=0; i<seqLen; i++)
        scanf("%d", &seq[i]);
    for(i=seqLen-1; i>=0; i--) {
        max=0;
        for(j=i+1; j<seqLen; j++) {
            if(seq[j]>seq[i] && max<accum[j])
                max = accum[j];
        }
        accum[i] = 1+max;
    }
    max = accum[0];
    for(i=1; i<seqLen; i++) {
        max = max < accum[i] ? accum[i] : max;
    }
    printf("%d\n", max);
    return 0;
}
