#include <iostream>

using namespace std;

//comparison is the basic operation to count - take swapping as the basic operation.
//types of input - DEC/ASC || first half ascending and second half descending || all elements same
//do only linear search - do only few things
//repeat it for ASC and DESC sorting
//find mode of the list - element which occurs maximum number of times and analyse its efficiency
//note down empirical value and compare with theoretical value
//try to make a mathematical model if possible and compare
//mode in an unsorted and sorted list too

int swap_count=0;
int comparison_count=0;
int length=12;

int in0[] = {11,23,4,5,33,67,8,4,5,3,2,1};
int in1[] = {12,11,10,9,8,7,6,5,4,3,2,1};
int in2[] = {1,2,3,4,5,6,7,8,9,10,11,12};
int in3[] = {1,2,3,4,5,6,12,11,10,9,8,7};
int in4[] = {6,6,6,6,6,6,6,6,6,6,6,6};
int lin0[] = {11,23,4,5,33,67,8,4,5,3,2,1};
int lin1[] = {11,12,10,9,8,7,6,5,4,3,2,1};
int lin2[] = {1,2,3,4,5,6,7,8,9,10,11,12};
int lin3[] = {1,2,3,4,5,6,12,11,10,9,8,7};
int lin4[] = {6,6,6,6,6,6,6,6,6,6,6,6};

void reset_list(){
    for(int i=0;i<length;i++)
        {
            in0[i] = lin0[i];
            in1[i] = lin1[i];
            in2[i] = lin2[i];
            in3[i] = lin3[i];
            in4[i] = lin4[i];
        }
}

void clear_vars(){
    swap_count=0;
    comparison_count=0;
}

void display(int z,int* arr, int length){
    if(z==0)
        cout<<"\nOriginal Array - ";
    else
        cout<<"\nSorted Array - ";

    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";

    if(z!=0)
    {
        cout<<"\nSwap Count - "<<swap_count<<" Comparison Count - "<<comparison_count<<endl;
        clear_vars();
    }
}

void exch(int* arr,int a, int b)
{
    swap_count++;
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void bubble_sort(int* arr, int length,int c){
    for(int i=1;i<length-1;i++)
        for(int j=length-1;j>=i;j--)
        {
            comparison_count++;
            if(c==0)
            {
                if(arr[j]<arr[j-1])
                    exch(arr,j,j-1);
            }
            else
            {
                if(arr[j]>arr[j-1])
                    exch(arr,j-1,j);
            }
        }
    display(1, arr, length);
}

void sel_sort(int* arr, int length,int c){
    int temp=arr[0], temp_pos=0;
    for(int i=0;i<length;i++)
    {
        temp = arr[i]; temp_pos = i;
        for(int j=i;j<length;j++)
        {
            comparison_count++;
            if(c==0)
            {
                if(arr[j]<temp)
                {
                    temp = arr[j];
                    temp_pos = j;
                }
            }
            else
            {
                if(arr[j]>temp)
                {
                    temp = arr[j];
                    temp_pos = j;
                }

            }
        }
        exch(arr,i,temp_pos);
    }
    display(1, arr, length);
}

void find_mode(int* arr, int length){
    int max=arr[0], mode_count=0,mode=0;
    for(int j=0;j<length;j++)
        if(arr[j]>max)
            max = arr[j];

    comparison_count = length;

    int* m_arr = new int[max+1];

    for(int j=0;j<=max;j++)
        m_arr[j] = 0;

    for(int j=0;j<length;j++)
        m_arr[arr[j]]++;

    for(int j=0;j<=max;j++)
        if(m_arr[j]>mode_count)
        {
            mode_count = m_arr[j];
            mode = j;
        }

    comparison_count += max;

    cout<<"\nmode = "<<mode<<" comparison count "<<comparison_count;
}



int main()
{
    cout<<"Sorting Hat";
    display(0,in0,12);display(0,in1,12);display(0,in2,12);display(0,in3,12);display(0,in4,12);
    cout<<"\n\nBubble Sort Ascending";
    bubble_sort(in0,12,0);bubble_sort(in1,12,0);bubble_sort(in2,12,0);bubble_sort(in3,12,0);bubble_sort(in4,12,0);
    cout<<"\n\nBubble Sort Descending";
    reset_list();
    bubble_sort(in0,12,1);bubble_sort(in1,12,1);bubble_sort(in2,12,1);bubble_sort(in3,12,1);bubble_sort(in4,12,1);
    cout<<"\n\nSelection Sort Ascending";
    reset_list();
    sel_sort(in0,12,0);sel_sort(in1,12,0);sel_sort(in2,12,0);sel_sort(in3,12,0);sel_sort(in4,12,0);
    cout<<"\n\nSelection Sort Descending";
    reset_list();
    sel_sort(in0,12,1);sel_sort(in1,12,1);sel_sort(in2,12,1);sel_sort(in3,12,1);sel_sort(in4,12,1);
    cout<<"\n\nMode Find";
    reset_list();
    find_mode(in0,12);find_mode(in1,12);find_mode(in2,12);find_mode(in3,12);find_mode(in4,12);


    return 0;
}
