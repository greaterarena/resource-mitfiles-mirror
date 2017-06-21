/*Max list*/

#include <stdio.h>
#include <stdlib.h>

int i, len,max_el;
int max_arr(int arr[]){
    max_el = arr[0];
    for(i = 0; i < len; i++){
           if(arr[i]>=max_el){
                max_el = arr[i];
           }
    }
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
    max_arr(inp_arr);

    printf("\n\n largest element -> %d\n", max_el);

    printf("\t\n printing original array now ->\n\n");

    for(i = 0; i < len; i++){
        printf("\t%d", inp_arr[i]);
    }

    printf("\n");
    return 0;
}
