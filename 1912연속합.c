#include <stdio.h>
#include <stdlib.h>

// 수들을 읽어나가면서 양수면 아묻따 읽어서 더한다. 음수를 만나면 지금까지 더했던 수를 후보 ll에 삽입하고 더했을때 아예 음수면 수 초기화해서 그 다음수부터 더해나가기 시작한다.
typedef struct node {
    int n;
    struct node* next;
} node;

typedef struct list {
    node* head;
    int nOn; // num Of nodes
} list;

list* newList() {
    list* temp = (list*)malloc(sizeof(list));
    node* dummy = (node*)malloc(sizeof(node));
    dummy->next = NULL;
    dummy->n=0;
    temp->head =dummy;
    temp->nOn = 0;
    return temp;
}

void addList(list* l, int num) {
    node* temp = (node*)malloc(sizeof(node));
    temp->n = num;
    temp->next = l->head->next;
    l->head->next = temp;
    l->nOn++;
}

int findMax(list* l) {
    node* current = l->head->next;
    int max = current->n;
    int i;
    for(i=1; i<l->nOn; i++) {
        current = current->next;
        max = max < current->n ? current->n : max;
    }
    return max;
}
int main(void) {
    list* sumL;
    int* nums;
    int length;
    int sum, max;
    int i;
    sumL = newList();
    scanf("%d", &length);
    nums = (int*)malloc(sizeof(int)*length);
    for(i=0; i<length; i++)
        scanf("%d", &nums[i]);
    sum = -1001;
    for(i=0; i<length; i++) {
        if(nums[i]<0) {
            addList(sumL, sum);
        }
        if(sum<0) sum=0;
        sum+=nums[i];
    }
    addList(sumL, sum);
    printf("%d\n", findMax(sumL));

    return 0;

}
