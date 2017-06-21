#include <stdio.h>

void adjust(int a[],int parent, int n)
{
	int child,key,temp;
	temp=a[parent];
	child=2*parent;
	while (child<=n) {
        if ((child<n) && (a[child]<a[child+1])) child++;
        if (temp>a[child]) break;
        else  {a[child/2]=a[child];
        child *=2; }
     }
    a[child/2]=temp;

}

void heapsort(int a[],int n)
{
	int i, temp;
	for (i=n/2;i>0; i--)
        adjust(a,i,n);
    printf("The heapified array\n");
	for (i=1;i<=n;i++)
        printf("%d\t",a[i]);
	for (i=n-1;i>0;i--){
        temp=a[1];a[1]=a[i+1];a[i+1]=temp;
        adjust(a,1,i);
	}
}
int main()
{
	int a[20],n,temp,i;
	printf("Enter the number of elements to sort\n");
	scanf("%d",&n);
	printf("Enter the elements to sort\n");
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	heapsort(a,n);
	printf("\nThe sorted array\n");
	for (i=1;i<=n;i++) printf("%d\t",a[i]);
	return 0;
}
