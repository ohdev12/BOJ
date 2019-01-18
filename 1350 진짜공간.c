#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, n, size;
    int* files;
    unsigned long long int answer=0, quotient;
    scanf("%d", &n);
    files = (int*)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        scanf("%d", &files[i]);
    scanf("%d", &size);
    for(i=0; i<n; i++) {
        quotient = files[i]/size;
        if(files[i]%size==0) answer+=(size*quotient);
        else answer+=(size*(quotient+1));
    }
    printf("%lld\n", answer);
    free(files);
    return 0;
}
