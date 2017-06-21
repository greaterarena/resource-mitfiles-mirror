#include <iostream>

using namespace std;

int comparison_count=0;

void clear_vars(){
    comparison_count=0;
}

void lin_search(int* arr, int length, int key){
    int flag=0;
    for(int i=1;i<length-1;i++)
    {
        comparison_count++;
        if(arr[i]==key)
        {
            flag = 1;
            break;
        }
    }
    cout<<"Comparison Count - "<<comparison_count<<endl;
    if(flag==1)
        cout<<"\nMatch Found\n";
    else
        cout<<"\nNo Match Found\n";
}

int main()
{
    int* tree = new int[100000];
    for(int i=0;i<100000;i++)
        tree[i]=i;
    lin_search(tree,100000,99877);
    return 0;
}
