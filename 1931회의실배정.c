#include <stdio.h>
#include <stdlib.h>

//insertion sort version! time OVER!
int count;
typedef struct node {
    int begin;
    int over;
    struct node* next;
    struct node* before;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
    int num;
} List;

List* generateList() {
    List* temp = (List*)malloc(sizeof(List));
    temp->head = NULL;
    temp->tail = NULL;
    temp->num = 0;
    return temp;
}

void insertNode(List* list, int b, int o) {
    Node* newN = (Node*)malloc(sizeof(Node));
    newN->begin = b;
    newN->over = o;
    newN->next = NULL;
    newN->before = list->tail;
    list->tail->next = newN;
    list->tail = newN;
    list->num++;
}

int main(void) {
    int avail=0;
    int answer=0; // the number of maximum available meetings
    int numM, i;
    int b, o;
    count=0;
    List* list;
    Node* current;
    Node* nextCurrent;
    Node* compare;
    list = generateList();
    scanf("%d", &numM);
    scanf("%d %d", &b, &o);
    list->head=(Node*)malloc(sizeof(Node));
    list->head->begin = b;
    list->head->over = o;
    list->head->before = NULL;
    list->head->next = NULL;
    list->tail = list->head;
    list->num++;
    for(i=1; i<numM; i++) {
        scanf("%d %d", &b, &o);
        insertNode(list, b, o);
    }

    //리스트 정렬해야 한다!!
    current = list->head->next;
    compare = list->head->next;
    for(i=1; i<numM; i++) {
        nextCurrent = current->next;
        while(compare->before!=NULL && compare->before->over > current->over) {
            compare = compare->before;
        }
        if(compare!=current) {
            current->before->next = current->next;
            current->next->before = current->before;
            if(compare->before == NULL) {
                compare->before = current;
                current->next = compare;
                list->head = current;
            } else {
                compare->before->next = current;
                current->before = compare->before;
                current->next = compare;
                compare->before = current;
            }
        }
        current = nextCurrent;
        compare = current;
    }

    current = list->head;
    for(i=0; i<numM; i++) {
        if(current->begin >= avail) {
            answer++;
            avail = current->over;
        }
        current = current->next;
    }

    printf("%d\n", answer);

    return 0;
}
