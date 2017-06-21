#include <iostream>
#include <cmath>
#include <list>

using namespace std;

list<int> cylinders;
int distancei = 0;

void input(){
    cout<<"Input the sequence - ";
    while(true){
        int temp = 0;
        cin>>temp;
        if(temp==-1)
            break;
        else
            cylinders.push_back(temp);
    }
}

void fcfs(){
    int start = cylinders.front();
    int i = 1;
    cylinders.pop_front();
    while(cylinders.size()>0){
        int endi = cylinders.front();
        distancei += abs(endi-start);
        cout<<"STEP "<<i++<<" Start - "<<start<<" End - "<<endi<<endl;
        start = endi;
        cylinders.pop_front();
    }
    cout<<endl<<"Total Distance Covered - "<<distancei;
}

int main()
{
    input();
    fcfs();
}
