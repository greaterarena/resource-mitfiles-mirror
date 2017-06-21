/* Binary Search */

#include <stdio.h>
#include <stdlib.h>

int i,j,len,temp,inp_arr[100],sch,found = -1, mid, f_arr, l_arr,sublen;

void sort_it(int arr[]){
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

void search_it(int arr[]){
    sublen = len;
    f_arr = 0;
    l_arr = len;
    for(i = f_arr; i < l_arr; i++){
    mid = sublen/2;
    if(sch<=mid){
        l_arr = mid;
    }
    if(sch>=mid){
        f_arr = mid;
    }
    for(i = f_arr; i < l_arr; i++){
        if(arr[i]==sch){
            found = i + 1;
        }
    }
    }

    if (found == -1){
            printf("\n\nSorry no match found\n");}
    else{
    printf("\n\n Match found at position -> %d\n", found);}
    printf("\n\n printing original array for verification now\n\n", found);
    for(i = 0; i < len; i++){
        printf("\t%d", arr[i]);
    }
    }

int main()
{
    printf(" Please specify the length of the array->");
    scanf("%d", &len);
    for(i = 0; i < len; i++){
        printf("\n Enter element number - %d ->  ", i+1);
        scanf("%d", &inp_arr[i]);
    }
    printf("\n Enter an element to search -> ");
    scanf("%d", &sch);
    sort_it(inp_arr);
    search_it(inp_arr);
    printf("\n\n the search has finished succesfully and has been verified\n\n");
    return 0;
}
