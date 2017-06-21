#include <iostream>
#include <vector>

#define PREEMPTIVE 0
#define PRIORITY 1 // for SELECTOR = 3 OR 4
#define AGING_FACTOR 0
#define QUANTIZE 0
#define QUANTUM 0
#define SELECTOR 4 // 0 FCFS 1 SJF 2 SRTF 3 PRI 4 PRI EMP 5 RR

using namespace std;

int GlobalTime = 0;

class process {
public:
    int PID, AT, BT, WT, TAT, Priority, Complete, BTOrigin;
    process(int a, int b, int c) {
        PID = a;
        AT = b;
        BTOrigin = c;
        BT = c;
        WT = TAT = Priority = 0;
        Complete = 0;
    }
    process(int a, int b, int c, int d) {
        PID = a;
        AT = b;
        BTOrigin = c;
        BT = c;
        WT = TAT = 0;
        Priority = d;
        Complete = 0;
    }

};

vector<process*> CPU;

void clockTick(process* Current) {
    GlobalTime++;
    for(vector<process*>::iterator i = CPU.begin(); i != CPU.end(); i++) {
        if((*i)->PID != Current->PID && (*i)->Complete == 0)
            (*i)->WT++;
    }
    Current->BT--;
    if(Current->BT == 0){
        Current->Complete = 1;
        Current->TAT = GlobalTime;
    }
}

void getInput(){
    int PIDTemp, ATTemp, BTTemp, PriorityTemp, Choice;
    while(true) {
        cout<<"\nNew Process - ";
        cin>>Choice;
        if(Choice==0)
            return;
        cout<<"\nEnter Process ID - ";
        cin>>PIDTemp;
        cout<<"\nEnter Burst Time - ";
        cin>>BTTemp;
        if(PRIORITY){
            cout<<"\nEnter Priority - ";
            cin>>PriorityTemp;
            CPU.push_back(new process(PIDTemp,GlobalTime,BTTemp,PriorityTemp));
        }
        else
            CPU.push_back(new process(PIDTemp,GlobalTime,BTTemp));
    }
}

int cpuDone(){
    for(vector<process*>::iterator i = CPU.begin(); i != CPU.end(); i++)
            if((*i)->Complete == 0)
                return 0;
    return 1;
}

void criticalInfoDump(){
    cout<<"Global Time - "<<GlobalTime<<" No of Processes - "<<CPU.size()<<endl;
    cout<<"PID\tBT\tAT\tWT\tPRI\tCOMP\n";
    for(vector<process*>::iterator i = CPU.begin(); i != CPU.end(); i++)
        cout<<(*i)->PID<<"\t"<<(*i)->BT<<"\t"<<(*i)->AT<<"\t"<<(*i)->WT<<"\t"<<(*i)->Priority<<"\t"<<(*i)->Complete<<"\t"<<(*i)->TAT<<endl;
}

process* fcfs(){
    for(int i = 0; i< CPU.size(); i++){
        if(CPU[i]->Complete!=1)
            return CPU[i];
    }
    return NULL;
}

process* sjf(){
    int MinAT = 99999;
    int MinBT = 99999;
    for(int i = 0; i< CPU.size(); i++){
        if(CPU[i]->Complete!=1 && CPU[i]->AT<=MinAT && CPU[i]->BTOrigin<=MinBT){
            MinAT = CPU[i]->AT;
            MinBT = CPU[i]->BTOrigin;
        }
    }
    for(int i = 0; i< CPU.size(); i++)
        if(CPU[i]->Complete!=1 && CPU[i]->AT==MinAT && CPU[i]->BTOrigin==MinBT)
            return CPU[i];

    return NULL;
}

process* srtf(){
    int MinBT = 99999;
    int Index, flag=0;
    for(int i = 0; i< CPU.size(); i++){
        if(CPU[i]->Complete!=1 && CPU[i]->BT<=MinBT){
            flag = 1;
            MinBT = CPU[i]->BT;
            Index = i;
        }
    }
    if(flag==1)
        return CPU[Index];
    else
        return NULL;
}

process* pri(){
    int MinPri = 99999;
    int MinAT = 99999;
    int Index, flag=0;
    for(int i = 0; i< CPU.size(); i++){
        if(CPU[i]->Complete!=1 && CPU[i]->AT <= MinAT && CPU[i]->Priority<=MinPri){
            flag = 1;
            MinAT = CPU[i]->AT;
            MinPri = CPU[i]->Priority;
            Index = i;
        }
    }
    if(flag==1)
        return CPU[Index];
    else
        return NULL;
}

process* priemp(){
    int MinPri = 99999;
    int Index, flag=0;
    for(int i = 0; i< CPU.size(); i++){
        if(CPU[i]->Complete!=1 && CPU[i]->Priority<=MinPri){
            flag = 1;
            MinPri = CPU[i]->Priority;
            Index = i;
        }
    }
    if(flag==1)
        return CPU[Index];
    else
        return NULL;
}

process* findNextProcessToBeExecuted(){
    process* temp;
    switch(SELECTOR){
        case 0: temp = fcfs();
                return temp;
        case 1: temp = sjf();
                return temp;
        case 2: temp = srtf();
                return temp;
        case 3: temp = pri();
                return temp;
        case 4: temp = priemp();
                return temp;
    }
}

void scheduler() {
    process* temp;
    while(!cpuDone()){
        criticalInfoDump();
        temp = findNextProcessToBeExecuted();
        if(temp==NULL) {
            cout<<"\nALL PROCESSES DONE\n";
            return;
        }
        clockTick(temp);
        getInput();
    }
}


int main() {
    getInput();
    scheduler();
    criticalInfoDump();
    return 0;
}
