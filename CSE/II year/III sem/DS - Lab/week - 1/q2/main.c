/* Selection Sort */

#include <stdio.h>
#include <stdlib.h>
int i,j,len,temp,inp_arr[100];

void sel_sort(int arr[]){
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
            if(arr[i]<arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            }
        }
    }

int main()
{
    printf("Please specify the length of the array->");
    scanf("%d", &len);
    for(i = 0; i < len; i++){
        printf("\n Enter element number - %d ->  ", i+1);
        scanf("%d", &inp_arr[i]);
    }
    printf("\n");
    sel_sort(inp_arr);

    for(i = 0; i < len; i++){
        printf("\t%d", inp_arr[i]);
    }

    printf("\n\n the array has been sorted\n\n");

    return 0;
}
