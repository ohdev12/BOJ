#include <stdio.h>

int main(void) {
    char str[1000];
    int i=0, j;
    int length=0;
    int axis, symstart, symend;
    int answerstart;
    scanf("%s", str);
    while(str[i]!='\0'){length++; i++;}
    axis = length-1;
    for(i=axis; i>=length/2; i--) {
        symstart = i;
        symend = i;
        if(str[i-1]==str[i]) {
            symstart--;
        }
        symend++;
        for(;symend<length;symend++) {
            if(str[symstart-1]==str[symend]) {
                symstart--;
            } else break;
        }
        if(symend>length-1) {
            answerstart = symstart;
        }

        symstart = i;
        symend = i;
        symend++;
        for(;symend<length;symend++) {
            if(str[symstart-1]==str[symend]) {
                symstart--;
            } else break;
        }
        if(symend>length-1) {
            if(answerstart>symstart) answerstart=symstart;
        }
    }
    printf("%d\n",length+answerstart);
    return 0;
}
