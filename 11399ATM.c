#include <stdio.h>
#include <stdlib.h>

void quickSort(int* array, int start, int end) {
    int temp, i;
    int front = start+1;
    int back = end;
    int pivot = array[start];
    while(1) {
        while(array[front]<pivot&&front<end)
            front++;
        while(array[back]>=pivot&&back>start)
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
    int numP;
    int i;
    int answer=0;
    int* P;
    scanf("%d", &numP);
    P = (int*)malloc(sizeof(int)*numP);
    for(i=0; i<numP; i++)
        scanf("%d", &P[i]);

    //정렬!!
    quickSort(P, 0, numP-1);
    for(i=0; i<numP; i++)
        answer += P[i]*(numP-i);
    printf("%d\n", answer);
    free(P);

    return 0;
}
