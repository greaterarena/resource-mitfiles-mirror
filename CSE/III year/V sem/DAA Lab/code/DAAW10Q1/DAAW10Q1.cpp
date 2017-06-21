#include <iostream>

using namespace std;
int n;
int min(int a,int b)
{
    return (a<b?a:b);
}
int** Floyd(int* D[])
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
            }
        }
    }
    return D;
}
int main()
{
    cout << "Enter the number of vertices:" << endl;
    cin>>n;
    cout<<"Enter the weight matrix:"<<endl;
    int** W=new int*[n];
    int** D=new int*[n];
    for(int i=0;
    i<n;i++)
    {
        W[i]=new int[n];
        D[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>W[i][j];
            D[i][j]=W[i][j];
        }
    }
    D=Floyd(D);
    cout<<"All pairs shortest path:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
