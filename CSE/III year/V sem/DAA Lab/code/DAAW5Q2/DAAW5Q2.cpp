#include<iostream>

using namespace std;

int comp_count = 0;

int Partition(int a[], int beg, int end)
{
    int p=beg, pivot=a[beg], loc;
    for(loc=beg+1;loc<=end;loc++)
    {
        comp_count++;
        if(pivot>a[loc])
        {
            a[p]=a[loc];
            a[loc]=a[p+1];
            a[p+1]=pivot;
            p=p+1;
        }
    }
    return p;
}


void QuickSort(int a[], int beg, int end)
{
    if(beg<end)
    {
        int p=Partition(a,beg,end);
        QuickSort(a,beg,p-1);
        QuickSort(a,p+1,end);
    }
}


int main()
{
    int i,n,beg=1;

    int k = 100000;

    int * arr = new int[k];
    for(int i=0;i<k;i++)
        arr[i] = k-i;

    QuickSort(arr,beg,k);

    cout<<"Comp Count - "<<comp_count;

    return 0;
}
