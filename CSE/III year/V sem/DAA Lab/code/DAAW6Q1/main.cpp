#include <iostream>

using namespace std;

int temp, temp2;

void ins_sort(int* a, int s){
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<i;j++){
            if(a[i]<a[j]){
                temp = a[j];
                a[j] = a[i];
                for(int k=i; k>j; k--)
                    a[k] = a[k-1];
                a[j+1] = temp;
                break;
            }
        }
    }
}

int main()
{
    int arr[] = {7,11,4,3,1,20,15,9,6,14};

    int size = 10;

    ins_sort(arr,size);

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";

    return 0;
}
