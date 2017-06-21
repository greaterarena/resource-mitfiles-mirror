#include <iostream>

using namespace std;

int main()
{
        int a[100],n,k,ret;
        int search(int a[],int,int);
        cout<<"Enter number count\n";
        cin>>n;
        cout<<"Enter the numbers\n";
        for(int i=0;i<n;i++)
                cin>>a[i];
        cout<<"Enter the number to be searched\n";
        cin>>k;
        ret=search(a,n,k);
        cout<<"Value of found is "<<ret<<"\n";
        return(0);
}


int search(int a[],int n ,int k)
{
        int found=0;
        for(int i=0;i<n;i++)
                if(a[i]==k)
                {
                        found=1;
                        break;
                }
                else found=-1;
        return (found);
}

