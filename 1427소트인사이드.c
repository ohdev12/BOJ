#include <stdio.h>
#include <stdlib.h>

int powerof(int a) {
    int i;
    int answer=1;
    for(i=0; i<a; i++)
        answer*=10;
    return answer;
}

void quickSort(int* array, int start, int end) {
    int temp, i;
    int front = start+1;
    int back = end;
    int pivot = array[start];
    while(1) {
        while(array[front]>pivot&&front<end)
            front++;
        while(array[back]<=pivot&&back>start)
            back--;
        if(front<back) {
            temp = array[front];
            array[front] = array[back];
            array[back] = temp;
        }
        else break;
    }
    array[start] = array[back];
    array[back] = pivot;
    if(start<back-1) quickSort(array, start, back-1);
    if(back+1<end) quickSort(array, back+1, end);
}

int main(void) {
    int N, i;
    int digits[10];
    int length;
    int init = 1000000000;
    int power;
    scanf("%d", &N);
    if(N==init) length=10;
    else if(N>=(init/=10)) length = 9; // same or bigger than 100000000
    else if(N>=(init/=10)) length = 8; // same or bigger than 10000000
    else if(N>=(init/=10)) length = 7; // same or bigger than 1000000
    else if(N>=(init/=10)) length = 6; // same or bigger than 100000
    else if(N>=(init/=10)) length = 5; // same or bigger than 10000
    else if(N>=(init/=10)) length = 4; // same or bigger than 1000
    else if(N>=(init/=10)) length = 3; // same or bigger than 100
    else if(N>=(init/=10)) length = 2; // same or bigger than 10
    else if(N>=(init/=10)) length = 1; // same or bigger than 1
    else length=0;
    for(i=length-1; i>=0; i--) {
        power = powerof(i);
        digits[i] = N/(power);
        N = N%(power);
    }
    for(i=length; i<10; i++) {
        digits[i] = 0;
    }
    quickSort(digits, 0, length-1);
    for(i=0; i<length; i++)
        printf("%d", digits[i]);
    return 0;
}
