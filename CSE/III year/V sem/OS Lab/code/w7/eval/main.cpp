#include <iostream>
#include <list>

using namespace std;

int switcher = 0, t=0;

int switch_count = 0,q1,q2,q3,q4;

int t1,t3;

// quantum
// q1 = main que
// q2 = main que internal
// q3 = second que
// q4 = second que int

class qel{
    public:
    int pid;
    int at;
    int bt;
    int rt;
    int tat;
    qel(int a, int b, int c){
        pid = a;at=b;bt=c;rt=bt;
    }
};

list<qel*> que[3];

void propogate(){
    switch(switcher){
        case 0: if(que[0].size()!=0)
                {
                    qel* temp = que[0].front();
                    temp->rt--;
                    t++;t1++;
                    cout<<"time - "<<t;
                    cout<<"Currently executing - "<<temp->pid<<" in queue - "<<switcher<<endl;
                    if(temp->rt==0)//ended
                    {
                        temp->tat = t;
                        que[3].push_back(que[0].front());
                        que[0].pop_front();
                    }
                    if(temp->bt-temp->rt==q2){//quanta ended
                        cout<<"here";
                        que[1].push_back(que[0].front());
                        que[0].pop_front();
                    }
                    // swicther calcs
                    if(t1==q1)
                    {
                        t1 = 0; //reset timer
                        switcher = !(switcher);
                    }
                }
                else{
                    t++;t1++;
                    cout<<"Que - "<<switcher<<"Empty"<<endl;
                    if(t1==q1)
                    {
                        t1 = 0; //reset timer
                        switcher = !(switcher);
                    }
                }
                break;

            case 1: if(que[1].size()!=0)
                    {
                        qel* temp = que[1].front();
                        temp->rt--;
                        t++;t3++;
                        cout<<"time - "<<t;
                        cout<<"Currently executing - "<<temp->pid<<" in queue - "<<switcher<<endl;
                        if(temp->rt==0)//ended
                        {
                            temp->tat = t;
                            que[3].push_back(que[1].front());
                            que[1].pop_front();
                        }
                        if(temp->bt-temp->rt==q4){//quanta ended
                            que[1].push_back(que[1].front());
                            que[1].pop_front();
                        }
                        // swicther calcs
                        if(t3==q3)
                        {
                            t3 = 0; //reset timer
                            switcher = !(switcher);
                        }
                    }
                    else{
                        t++;t3++;
                        cout<<"Que - "<<switcher<<"Empty"<<endl;
                        if(t3==q3)
                        {
                            t1 = 0; //reset timer
                            switcher = !(switcher);
                        }
                    }
                    break;



    }
}

void add(){
    int t1,t2;
    cout<<"\npid bt : ";
    cin>>t1>>t2;
    qel* temp = new qel(t1,t,t2);
    que[switcher].push_back(temp);
}

int main()
{
    int c;
    cout<<"Enter the Quanta - ";
    cin>>q1>>q2>>q3>>q4;
    t1=t3=0;
    while(1){
        cout<<"new process? : ";
        cin>>c;
        switch(c){
            case 0: propogate();
                    break;
            case 1: add();
                    propogate();break;
            default: propogate();break;
        }
    }
}
