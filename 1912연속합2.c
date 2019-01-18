#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* nums;
    int current_sum=-1001;
    int current_max=-1001;
    int i, length;
    scanf("%d", &length);
    nums = (int*)malloc(sizeof(int)*length);
    for(i=0; i<length; i++)
        scanf("%d", &nums[i]);
    for(i=0; i<length; i++) {
        if(nums[i]<0) {
            current_max = current_max < current_sum ? current_sum : current_max;
        }
        if(current_sum<0) current_sum=0;
        current_sum += nums[i];
    }
    current_max = current_max < current_sum ? current_sum : current_max;
    printf("%d\n", current_max);
    return 0;
}
