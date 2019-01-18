#include <stdio.h>
#include <stdlib.h>

int median(int* array, int start, int end) {
    int mid = (start+end)/2;
    if(array[start]>array[mid]) {
        if(array[start]>array[end]) return array[mid] > array[end] ? mid : end;
        else return start;
    } else {
        if(array[mid]>array[end]) return array[start] > array[end] ? start : end;
        else return mid;
    }
}

void quickSort(int* mover, int* mbegin, int start, int end) {
    int temp, i;
    int front = start+1;
    int back = end;
    int med = median(mover, start, end);
    int pivot = mover[med];
    temp = mover[med];
    mover[med] = mover[start];
    mover[start] = temp;
    temp = mbegin[med];
    mbegin[med] = mbegin[start];
    mbegin[start] = temp;
    while(1) {
        while(mover[front]<=pivot&&front<end)
            front++;
        while(mover[back]>pivot&&back>start)
            back--;
        if(front<back) {
            temp = mover[front];
            mover[front] = mover[back];
            mover[back] = temp;

            temp = mbegin[front];
            mbegin[front] = mbegin[back];
            mbegin[back] = temp;
        }
        else break;
    }
    mover[start] = mover[back];
    mover[back] = pivot;
    temp = mbegin[start];
    mbegin[start] = mbegin[back];
    mbegin[back] = temp;
    if(start<back-1) quickSort(mover, mbegin, start, back-1);
    if(back+1<end) quickSort(mover, mbegin, back+1, end);
}



int main(void) {
    int avail=0;
    int answer=0; // the number of maximum available meetings
    int numM, i;
    int *mbegin;
    int *mover;
    scanf("%d", &numM);
    mbegin = (int*)malloc(sizeof(int)*numM);
    mover = (int*)malloc(sizeof(int)*numM);
    for(i=0; i<numM; i++)
        scanf("%d %d", &mbegin[i], &mover[i]);
    quickSort(mover, mbegin, 0, numM-1);

    for(i=0; i<numM; i++) {
        if(mbegin[i]>=avail) {
            answer++;
            avail = mover[i];
        }
    }

    printf("%d\n", answer);

    free(mbegin);
    free(mover);

    return 0;
}

