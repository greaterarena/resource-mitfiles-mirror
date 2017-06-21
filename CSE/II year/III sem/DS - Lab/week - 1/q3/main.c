/* Linear Search */

#include <stdio.h>
#include <stdlib.h>

int i,len,temp,inp_arr[100],sch,found = -1;

void search_it(int arr[]){
    for(i = 0; i < len; i++){
        if(arr[i]==sch){
            found = i + 1;
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
    search_it(inp_arr);
    printf("\n\n the search has finished succesfully and has been verified\n\n");
    return 0;
}
