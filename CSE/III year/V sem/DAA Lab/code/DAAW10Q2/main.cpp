#include <iostream>

using namespace std;
int* weights;
int* values;
int** V;
int n,W;
int max(int a,int b)
{
    return (a>b?a:b);
}
int MFKnapsack(int i,int j)
{
    int value;
    if(i-1>=0 && j-1>=0 && V[i][j]<0)
    {
        if(j<weights[i])
            value=MFKnapsack(i-1,j);
        else
            value=max(MFKnapsack(i-1,j),values[i]+MFKnapsack(i-1,j-weights[i]));
        V[i][j]=value;
    }
    return V[i][j];
}
int main()
{
    cout << "Enter number of items:" << endl;
    cin>>n;
    cout<<"Enter the capacity of the knapsack:\n";
    cin>>W;
    weights=new int[n+1];
    values=new int[n+1];
    V=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        V[i]=new int[W+1];
    }
    cout<<"Enter the weights for each item:\n";
    for(int i=1;i<=n;i++)
    {
        cin>>weights[i];
    }
    cout<<"Enter the values for each item:\n";
    for(int i=1;i<=n;i++)
    {
        cin>>values[i];
    }
    for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                V[i][j]=0;
            else
                V[i][j]=-1;
        }
      }
    cout<<"Answer: "<<MFKnapsack(n,W);
    return 0;
}
