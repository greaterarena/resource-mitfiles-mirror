#include <iostream>
#include <cmath>
#include <list>

using namespace std;

list<int> cylinders;
int distancei = 0;
int lefti , righti, dir = 0;
//0 - L to R
//1 - R to L

void input(){
    int temp;
    cout<<"Input the head position - ";
    cin>>temp;
    cylinders.push_back(temp);
    cout<<"Input start - ";
    cin>>lefti;
    cout<<"Input end - ";
    cin>>righti;
    cylinders.push_back(lefti);
    cylinders.push_back(righti);
    cout<<"Input the seek sequence - ";
    while(true){
        cin>>temp;
        if(temp==-1)
            break;
        else
            cylinders.push_back(temp);
    }
    //cylinders.sort();
}

void more_input(){
    int temp;
    cout<<endl<<"Add more cylinders to seek sequence - ";
    while(true){
        cin>>temp;
        if(temp==-1)
            break;
        else if(temp==-2)
        {
            more_input();
            break;
        }
        else
            cylinders.push_back(temp);
    }
    //cylinders.sort();
}

void set_dir(){
    cout<<endl<<"DIR 0 - LR | 1 - RL > ";
    cin>>dir;
}

int check_maadi(int start,int endr,int val){
    if(dir==0){
        if(val<0)
            return 0;
        else return 1;
    }
    else{
        if(val>0)
            return 0;
        else return 1;
    }
}

int exists(int x){
    for(list<int>::iterator iter = cylinders.begin(); iter!=cylinders.end(); iter++)
        if(*iter == x)
            return 1;
    return 0;
}

int killer(){
    if(exists(lefti)&&exists(righti)&&cylinders.size()==2)
        return 1;
    if(cylinders.size()==1){
        if(exists(lefti)||exists(righti))
            return 1;
    }
    return 0;
}

void c_scan(){
    int start = cylinders.front();
    cylinders.pop_front();
    int min_dist = 99999;
    int next_min = 0, i=0;
    while(cylinders.size()>0){
        for(list<int>::iterator iter = cylinders.begin(); iter!=cylinders.end(); iter++){
            cout<<" "<<*iter;
            int endi = *iter;
            if(start==endi)
                continue;
            int temp = endi-start;
            if(check_maadi(start,endi,temp)){
                temp = abs(temp);
                if(temp<min_dist&&temp>0){
                    min_dist = temp;
                    next_min = endi;
                }
            }
        }
        cout<<endl<<"STEP "<<i++<<" Start - "<<start<<" End - "<<next_min<<" DIR - "<<dir<<endl;
        distancei += abs(next_min-start);
        if(killer())
            break;
        start = next_min;
        if(next_min==lefti&&dir==1){
            //dir = 0;
            cout<<endl<<"STEP "<<i++<<" Start - "<<next_min<<" End - "<<righti<<" DIR - "<<dir<<endl;
            distancei += abs(righti-lefti);
            start = righti;
            if(!exists(righti))
                cylinders.push_back(righti);
        }
        else if(next_min==righti){
            //dir = 1;
            cout<<endl<<"STEP "<<i++<<" Start - "<<next_min<<" End - "<<lefti<<" DIR - "<<dir<<endl;
            distancei += abs(lefti-righti);
            start = lefti;
            if(!exists(lefti))
                cylinders.push_back(lefti);
        }
        cylinders.remove(next_min);
        min_dist = 99999;
        more_input();
    }
    cout<<endl<<"Total Distance Covered - "<<distancei;
}

int main()
{
    input();
    set_dir();
    c_scan();
    return 0;
}
