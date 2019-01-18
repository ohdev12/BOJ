#include <stdio.h>

int main(void) {
    char str[151];
    int i=0;
    int status=1;
    gets(str);
    while(str[i]) {
        switch(status) {
        case 1:
            if(str[i]=='0') status=6;
            else status=2;
            break;
        case 2:
            if(str[i]=='0') status=3;
            else status=8;
            break;
        case 3:
            if(str[i]=='0') status=4;
            else status=8;
            break;
        case 4:
            if(str[i]=='0') status=4;
            else status = 5;
            break;
        case 5:
            if(str[i]=='0') status=6;
            else {
                if(str[i+1]=='0' && str[i+2]=='0') status=2;
                else status=5;
            }
            break;
        case 6:
            if(str[i]=='0') status=8;
            else status=7;
            break;
        case 7:
            if(str[i]=='0') status=6;
            else status=2;
            break;
        }
        i++;
    }
    if(status==5 || status==7) printf("SUBMARINE");
    else printf("NOISE");
    return 0;
}
