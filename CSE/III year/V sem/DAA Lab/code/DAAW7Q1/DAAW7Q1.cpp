#include <iostream>
#include <stdlib.h>

using namespace std;

int size = 5, count = 0;

int stat[] = {0,0,0,0,0};

int am[][5] = {
                {0,0,1,0,0},
                {0,0,1,0,0},
                {0,0,0,1,1},
                {0,0,0,0,1},
                {0,0,0,0,0},
              };

int stat_check(){
    for(int i=0; i<size; i++)
        if(stat[i]==0)
            return 0;
    return 1;
}

int find(){
    int flager = 0;
    for(int i=0; i<size; i++){
        flager = 0;
        if(stat[i]==1)
            continue;
        else{
            for(int j=0; j<size; j++){
                if(am[j][i]==1){
                    flager = 1;
                    break;
                }
            }
            if(flager!=1){
                stat[i] = 1;
                return i;
            }
        }
    }
    return -99;
}

void topological(){
    int k = -1;
    while(!stat_check())
    {
        k = find();
        if(k!=-99){
            cout<<"C"<<k+1<<" ";
            for(int i=0;i<size;i++)
            am[k][i] = 0;
        }
        else
            count++;
        if(count>size*size){
            cout<<"Cycle Detected";
            break;
        }
    }
}

int main()
{
    topological();
    return 0;
}
