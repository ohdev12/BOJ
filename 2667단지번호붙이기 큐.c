#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    int y;
    struct node* next;
} node;

typedef struct queue {
    node* head;
    node* tail;
    int number;
} queue;

queue* generateQ() {
    queue* newQ = (queue*)malloc(sizeof(queue));
    newQ->head=NULL;
    newQ->tail=NULL;
    newQ->number=0;
}

void enqueue(queue* q, node* add) {
    if(q->number==0)
        q->head=add;
    else
        q->tail->next = add;
    q->tail = add;
    q->number++;
}

node* createNode(int a, int b) {
    node* newN = (node*)malloc(sizeof(node));
    newN->next=NULL;
    newN->x = a;
    newN->y = b;
    return newN;
}

void process(stack* st,int x, int y, int a, int b){
    if(map[a][b]=='1' && danji[a][b]==0) {
        danji[a][b]=danji[x][y];
        gagusu[danji[x][y]]++;
        push(st, createNode(a, b));
    }
}
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
    int N, i, j, count=0;
    int x, y;
    char** danji;
    int* gagusu;
    char** map;
    node* current;
    queue* q = generateQ();
    scanf("%d", &N);
    map = (char**)malloc(sizeof(char*)*N);
    danji = (short**)malloc(sizeof(short*)*N);
    gagusu = (int*)malloc(sizeof(int)*(N*N));
    for(i=0; i<N; i++) {
        map[i] = (char*)malloc(sizeof(char)*N);
        danji[i] = (char*)malloc(sizeof(char)*N);
        scanf("%s", map[i]);
        for(j=0; j<N; j++) {
            danji[i][j] = 0; // not visited if danji is 0!
            gagusu[(i*N)+j]=0;
        }
    }
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(map[i][j]=='1' && danji[i][j]==0) {
                danji[i][j] = ++count;
                gagusu[danji[i][j]]++;
                push(st, createNode(i, j));
                while(!isEmpty(st)) {
                    current = pop(st);
                    x = current->x;
                    y = current->y;
                    if(x>0)
                        process(st, x, y, x-1, y);
                    if(x<N-1)
                        process(st, x, y, x+1, y);
                    if(y>0)
                        process(st, x, y, x, y-1);
                    if(y<N-1)
                        process(st, x, y, x, y+1);
                    free(current);
                }
            }
        }
    }
    printf("%d\n", count);
    if(1<count) quickSort(gagusu, 1, count);
    for(i=1; i<=count; i++) {
        printf("%d\n", gagusu[i]);
    }
    free(map);
    free(danji);
    free(gagusu);
    return 0;
}
