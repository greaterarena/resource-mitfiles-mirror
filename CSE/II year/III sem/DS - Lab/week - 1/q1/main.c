#include <stdio.h>


int i, len;
int sumarr(int arr[], int length){
    int sum = 0;
    for(i = 0; i < length; i++){
           sum += arr[i];
    }
    return sum;
}



int main()
{
    int inp_arr[100];
    printf("Please specify the length of the array->");
    scanf("%d", &len);
    for(i = 0; i < len; i++){
        printf("\n Enter element number - %d ->  ", i+1);
        scanf("%d", &inp_arr[i]);
    }
    int sum_ret = sumarr(inp_arr, len);
    printf("\t\n The sum of the given array -> %d\n", sum_ret);

    for(i = 0; i < len; i++){
        printf("\t%d", inp_arr[i]);
    }

    return 0;
}
