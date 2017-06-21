/* Sum of matrices */

#include <stdio.h>
#include <stdlib.h>

int i,k,j,c_len,r_len,a_arr[100][50],b_arr[100][50],c[100][50];

void add(int arr1[][50], int arr2[][50]){
    for(i = 0; i < r_len; i++){
        for(j = 0; j < c_len; j++){
         c[i][j] = arr1[i][j] + arr2[i][j];
        }}
}


int main()
{
    printf("Please specify the dimensions of the array->");
    printf("\n rows ->");
    scanf("%d", &r_len);
    printf("\n columns ->");
    scanf("%d", &c_len);
    for(k=0;k<2;k++){
    for(i = 0; i < r_len; i++){
        printf("\nbegin entering values for array -> %d\n", k);
        for(j = 0; j < c_len; j++){
        printf("\n Enter element at row - %d ", i+1);
        printf("- column - %d ->  ", j+1);
        if(k==0){scanf("%d", &a_arr[i][j]);}
        if(k==1){scanf("%d", &b_arr[i][j]);}
    }}}

    add(a_arr,b_arr);

    printf("\n\n printing sum array -> \n\n");
    for(i = 0; i < r_len; i++){
        for(j = 0; j < c_len; j++){
         printf("\t%d",c[i][j]);
         }
    printf("\n");
    }

    return 0;
}
