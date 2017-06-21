#include <iostream>
#include <list>
#include <vector>

using namespace std;

int c;
float hc=0,tc=0;

list<int> page;
vector<int> input;

int vc = 0;

void display(){
    cout<<"PAGES - ";
    for(list<int>::iterator t = page.begin(); t != page.end(); t++)
        cout<<*t<<" ";
    cout<<"\n";
}
int exists(int temp){
    for(list<int>::iterator t = page.begin(); t != page.end(); t++)
        if(*t == temp)
            return 1;
    return 0;
}


void display1(){
    cout<<"Input Sequence - ";
    for(vector<int>::iterator t = input.begin(); t != input.end(); t++)
        cout<<*t<<" ";
    cout<<"\n";
}

void optimal(){
    int temp = vc;
    for(list<int>::iterator t = page.begin(); t != page.end(); t++){
        if(temp!=input.size()-3&&(*t==input[temp+1]||*t==input[temp+2])){
            continue;
        }
        else{
            *t = input[vc++];
            break;
        }
    }
}

int main()
{
    cout<<"\nEnter size of Memory - ";
    cin>>c;
    cout<<"\nEnter complete input sequence followed by -1 to terminate\n\n";
    while(true){
        int temp;
        cin>>temp;
        if(temp==-1)
            break;
        else
            input.push_back(temp);
    }
    display1();

    while(vc<input.size()){
        cout<<"\nNext Input - "<<input[vc]<<endl;
        if(page.size()!=c){
            page.push_back(input[vc++]);
            tc++;
        }
        else{
            if(exists(input[vc])){
                cout<<"\nHIT\n";
                vc++;
                hc++;
            }
            else
                optimal();
            tc++;
        }
        display();
    }
    cout<<"\nHits - "<<hc<<" Hit rate - "<<(hc/tc);
    return 0;
}
