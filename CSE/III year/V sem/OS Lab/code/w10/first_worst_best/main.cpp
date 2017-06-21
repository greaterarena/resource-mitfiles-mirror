#include <iostream>
#include <vector>
#include <list>
#define selector 1

using namespace std;

class proc{
    public: int pid;
            int sz;
            int a;
    proc(int a, int b){
        pid = a;
        sz = b;
        a = 0;
    }
};

class block{
    public: int addr;
            int sz;
            int pid;
            int psz;
            int all;
    block(int a, int b){
        addr = a;
        sz = b;
        pid = 0;
        psz = 0;
        all = 0;
    }
    void allot(proc* temp){
        pid = temp->pid;
        psz = temp->sz;
        temp->a = 1;
        all = 1;
    }
};

vector<block*> mem;
vector<proc*> p;
list<int> aindex;
list<int> sindex;

void display(){
    if(mem.size()>0){
        cout<<"\nMEMORY DUMP\n";
        cout<<"|| ADDR\tSZ\tPID\tOCC ||\n";
        cout<<"||--------------------------||\n";
        for(vector<block*>::iterator t = mem.begin(); t!=mem.end(); t++)
            cout<<"|| "<<(*t)->addr<<"\t"<<(*t)->sz<<"\t"<<(*t)->pid<<"\t"<<(*t)->psz<<"   ||\n";
    }
    if(p.size()>0){
        cout<<"\nUNALLOCATED PROCESSES\n";
        cout<<"|| PID\tSZ ||\n";
        cout<<"||---------||\n";
        for(vector<proc*>::iterator t = p.begin(); t!=p.end(); t++)
            if((*t)->a==0||(*t)->a==-1)
                cout<<"|| "<<(*t)->pid<<"\t"<<(*t)->sz<<"  ||\n";
    }
}

void new_block(){
    int a, b;
    cout<<"\nBase Address - ";cin>>a;
    cout<<"\nBlock Size - ";cin>>b;
    aindex.push_back(a);
    sindex.push_back(b);
    mem.push_back(new block(a,b));
}

void new_process(){
    int a, b;
    cout<<"\nProcess ID - ";cin>>a;
    cout<<"\nProcess Size - ";cin>>b;
    p.push_back(new proc(a,b));
}

void worst_fit(){
    if(sindex.size()>0){
        sindex.sort();
        sindex.reverse();
        cout<<endl;
        int s = sindex.front();
        proc* temp;
        for(vector<proc*>::iterator t = p.begin(); t!=p.end(); t++){
            if((*t)->sz<=s&&(*t)->a==-1){
                sindex.pop_front();
                temp = *t;
                for(vector<block*>::iterator o = mem.begin(); o!=mem.end(); o++)
                    if((*o)->sz == s && (*o)->all==0){
                        (*o)->allot(temp);
                        break;
                    }
                break;
            }
        }
    }
}

void best_fit(){
    if(sindex.size()>0){
        sindex.sort();
        /*cout<<"\navailable indexes - ";
        for(list<int>::iterator t = sindex.begin(); t!=sindex.end(); t++)
            cout<<*t<<" ";*/
        cout<<endl;
        int s, flag;
        for(vector<proc*>::iterator t = p.begin(); t!=p.end(); t++){
                flag=0;
            for(list<int>::iterator w = sindex.begin(); w!=sindex.end(); w++){
                if((*t)->sz<=(*w)&&(*t)->a==-1){
                    s = *w;
                for(vector<block*>::iterator y = mem.begin(); y!=mem.end(); y++)
                    if((*y)->sz == s && (*y)->all==0){
                        (*y)->allot(*t);
                        flag = 1;
                        sindex.remove(s);
                        break;
                    }
                if(flag==1)
                    break;
                }
            }
        }
    }
}

void first_fit(){
    if(aindex.size()>0){
        aindex.sort();
        /*cout<<"\navailable indexes - ";
        for(list<int>::iterator t = aindex.begin(); t!=aindex.end(); t++)
            cout<<*t<<" ";
        cout<<endl;*/
        int s = 0, flag;
        block* tempy;
        for(vector<proc*>::iterator t = p.begin(); t!=p.end(); t++){
            for(list<int>::iterator w = aindex.begin(); w!=aindex.end(); w++){
                for(vector<block*>::iterator y = mem.begin(); y!=mem.end(); y++){
                    if((*y)->addr == (*w) && (*y)->all==0){
                       s = (*y)->sz;
                       tempy = (*y);
                       break;
                    }
                }
                if(s==0)break;
                if((*t)->sz<=s && (*t)->a==-1){
                    tempy->allot(*t);
                    aindex.remove((*w));
                    break;
                }
            }
        }
    }
}

int main()
{
   while(true){
        int c;
        display();
        cout<<"\n1. New Block";
        cout<<"\n2. New Process";
        cout<<"\n3. Exit";
        cout<<"\nChoice - ";
        cin>>c;
        switch(c){
            case 1: new_block();break;
            case 2: new_process();
                    switch(selector){
                        case 1: worst_fit();break;
                        case 2: best_fit();break;
                        case 3: first_fit();break;
                    }break;
            case 3: return 0;
            deafult: break;
        }
    }
    return 0;
}
