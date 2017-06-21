#include <iostream>
using namespace std;
int* c, comp_count = 0;
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        comp_count++;
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
int main()
{
    int i;
    //int a[] = {1,5,3,6,8,4,5,6,4,3,65,87,65,4,6,43};
    int k = 10;

    int * arr = new int[k];
    c = new int[k];
    for(int i=0;i<k;i++)
        arr[i] = k-i;

    mergesort(arr, 0, k-1);

    cout<<"comp count - "<<comp_count;
}
