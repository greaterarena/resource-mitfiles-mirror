#include <iostream>
#include <list>

using namespace std;

int c;
float hc=0,tc=0;

list<int> page;

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

int main()
{
    cout<<"\nEnter size of Memory - ";
    cin>>c;
    while(true){
        int temp;
        cout<<"\nNext page - ";
        cin>>temp;
        if(temp == - 1){
            cout<<"\nHits - "<<hc<<" Hit rate - "<<(hc/tc);
            return 0;
        }
        if(page.size()!=c){
            page.push_back(temp);
            tc++;
        }
        else{
            if(!exists(temp)){
                page.pop_front();
                page.push_back(temp);
            }
            else{
                cout<<"\nHIT\n";
                hc++;
            }
            tc++;
        }
        display();
    }
    return 0;
}
