#include <stdio.h>

int main(void) {
    int n, i, answer=0;
    int temp1=1, temp2=2;
    scanf("%d", &n);
    if(n==1) answer = temp1;
    else if(n==2) answer = temp2;
    else {
        for(i=0; i<n-2; i++) {
            answer = temp1+temp2;
            if(answer > 10007) answer -= 10007;
            temp1 = temp2;
            temp2 = answer;
        }
    }
    printf("%d", answer);
    return 0;
}
