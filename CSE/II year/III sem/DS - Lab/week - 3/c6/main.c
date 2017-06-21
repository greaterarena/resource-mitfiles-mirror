#include <stdio.h>
#include <stdlib.h>

int arr_sum( int arr[], int n )
{
if (n) { return arr_sum(arr,n-1)+arr[n-1]; }
return 0;
}

int main(){
   int inp_arr[100],len,i;
    printf("Please specify the length of the array->");
    scanf("%d", &len);
    for(i = 0; i < len; i++){
        printf("\n Enter element number - %d ->  ", i+1);
        scanf("%d", &inp_arr[i]);
    }
    int sum_ret = arr_sum(inp_arr, len);
    printf("\t\n The sum of the given array -> %d\n", sum_ret);

}

