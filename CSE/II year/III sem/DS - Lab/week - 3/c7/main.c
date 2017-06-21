#include <stdio.h>
#include <stdlib.h>

int binsrch(int a[], int x, int low, int high)
{ int mid;
if (low >high) return (-1);
  else
{ mid=(low+high)/2;
return (x==a[mid] ? mid  : x<a[mid] ? binsrch(a,x,low, mid-1) : binsrch(a,x, mid+1, high));}}

int main()
{
   int inp_arr[100],len,i,k;
    printf("Please specify the length of the array -> ");
    scanf("%d", &len);
    for(i = 0; i < len; i++){
        printf("\n Enter element number - %d -> ", i+1);
        scanf("%d", &inp_arr[i]);
    }
    printf("\n key to search for -> ");
    scanf("%d", &k);
    int m = binsrch(inp_arr,k,0,len-1);
    printf("\t\n match found at -> %d\n", m+1);
}
