#include<iostream>
#define size 10
using namespace std;

int arr_xHandler(int *a,int i)
{
    if(i<0||i>size-1)
        throw "Array out of Bounds";
    return a[i];
}

int main()
{
    int arr[size];
    int i,z;
    cout<<"\n\nInput "<<size<<" Elements :: ";
    for(int i=0;i<size;cin>>arr[i],i++);
    do
    {
        cout<<"\n\nIndex : ";
        cin>>i;
        try
        {
            z=arr_xHandler(arr,i);
        }
        catch(const char *s)
        {
            cout<<"\nException : "<<s<<"Try Again."<<endl;
            cout<<"\n\nDo You want to Exit?\n";
            cout<<"\n0. No\n\n1. Yes\n\nEnter Choice :: ";
            int t;
            cin>>t;
            if(t)
                break;
            else
                continue;
        }
        cout<<"\n\narr[" <<i<<"]= "<<z<<endl;
        cout<<"\n\nDo You want to Exit?\n";
        cout<<"\n0. No\n\n1. Yes\n\nEnter Choice :: ";
        int y;
        cin>>y;
        if(y)
            break;
    }
    while(true);
    return 0;
}
