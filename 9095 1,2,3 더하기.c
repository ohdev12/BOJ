#include <stdio.h>
#include <stdlib.h>

int tresFibo(int n) {
    int temp1=1, temp2=2, temp3=4;
    int i, answer;
    if(n==1) return temp1;
    else if(n==2) return temp2;
    else if(n==3) return temp3;
    else {
        for(i=0; i<n-3; i++) {
            answer=temp1+temp2+temp3;
            temp1=temp2;
            temp2=temp3;
            temp3=answer;
        }
    }
    return answer;
}

int main(void) {
    int temp1=1, temp2=2, temp3=4;
    int i, n;
    int* ns;
    scanf("%d", &n);
    ns = (int*)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        scanf("%d", &ns[i]);
    for(i=0; i<n; i++){
        printf("%d\n", tresFibo(ns[i]));
    }
    free(ns);
    return 0;
}
