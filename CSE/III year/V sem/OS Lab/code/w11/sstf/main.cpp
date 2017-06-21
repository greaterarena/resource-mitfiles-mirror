#include <iostream>
#include <cmath>
#include <list>

using namespace std;

list<int> cylinders;
int distancei = 0;

void input(){
    int temp;
    cout<<"Input the head position - ";
    cin>>temp;
    cylinders.push_back(temp);
    cout<<"Input the seek sequence - ";
    while(true){
        cin>>temp;
        if(temp==-1)
            break;
        else
            cylinders.push_back(temp);
    }
}

void more_input(){
    int temp;
    cout<<endl<<"Add more cylinders to seek sequence - ";
    while(true){
        cin>>temp;
        if(temp==-1)
            break;
        else
            cylinders.push_back(temp);
    }
}

void sstf(){
    int start = cylinders.front();
    cylinders.pop_front();
    int min_dist = 99999;
    int next_min, i=0;
    while(cylinders.size()>0){
        for(list<int>::iterator iter = cylinders.begin(); iter!=cylinders.end(); iter++){
            int endi = *iter;
            int temp = abs(endi-start);
            if(temp<min_dist){
                min_dist = temp;
                next_min = endi;
            }
        }
        cout<<endl<<"STEP "<<i++<<" Start - "<<start<<" End - "<<next_min<<endl;
        distancei += abs(next_min-start);
        start = next_min;
        cylinders.remove(next_min);
        min_dist = 99999;
        more_input();
    }
    cout<<endl<<"Total Distance Covered - "<<distancei;
}

int main()
{
    input();
    sstf();
    return 0;
}
