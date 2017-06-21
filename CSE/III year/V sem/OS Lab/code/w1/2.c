#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Enter n - ");
	int n;
	scanf("%d",&n);
	int i;
	int *arr;
        arr  = (int*) (malloc(sizeof(int)*n));
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	for(i=0; i<n; i++)
		printf("\n%d",arr[i]);	
	return 0;
}
