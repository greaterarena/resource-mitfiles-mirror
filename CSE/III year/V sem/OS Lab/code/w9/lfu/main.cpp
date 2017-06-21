#include <iostream>
#include <list>

using namespace std;

int c;
float hc=0,tc=0;

class proc{
    public:
        int id;
        int c;
    proc(int a, int b){
        id = a; c = b;
    }
};

list<proc> page;

void display(){
    cout<<"PAGES - ";
    for(list<proc>::iterator t = page.begin(); t != page.end(); t++)
        cout<<(*t).id<<" ";
    cout<<"\n";

    cout<<"Counters - ";
    for(list<proc>::iterator t = page.begin(); t != page.end(); t++)
        cout<<(*t).c<<" ";
    cout<<"\n";
}

void inc(int temp){
    for(list<proc>::iterator t = page.begin(); t != page.end(); t++)
        if((*t).id != temp)
            (*t).c--;
}

int exists(int temp){
    for(list<proc>::iterator t = page.begin(); t != page.end(); t++)
        if((*t).id == temp)
        {
            (*t).c=0;
            return 1;
        }
    return 0;
}

void lru(int temp){
    int cmax=100;
    for(list<proc>::iterator t = page.begin(); t != page.end(); t++)
        if((*t).c<=cmax)
            cmax = (*t).c;
    for(list<proc>::iterator t = page.begin(); t != page.end(); t++)
        if((*t).c==cmax){
            (*t).c = 0;
            (*t).id = temp;
        }
}

int main()
{
    cout<<"\nEnter size of Memory - ";
    cin>>c;
    while(true){
        int temp;
        cout<<"\nNext Page - ";
        cin>>temp;
        if(temp == - 1){
            cout<<"\nHits - "<<hc<<" Hit rate - "<<(hc/tc);
            return 0;
        }
        if(page.size()!=c){
            if(exists(temp))
                inc(temp);
            else{
                proc l(temp, 0);
                page.push_back(l);
                inc(temp);
            }
            tc++;
        }
        else{
            if(exists(temp)){
                cout<<"\nHIT\n";
                hc++;
                inc(temp);
            }
            else{
                lru(temp);
                inc(temp);
            }
            tc++;
        }
        display();
    }
    return 0;
}
