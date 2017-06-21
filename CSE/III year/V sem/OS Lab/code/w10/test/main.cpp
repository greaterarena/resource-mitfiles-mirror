#include <stdlib.h>
#include <iostream>
#include <list>

using namespace std;

int n, m, safe_count=0;
int *avail, **mx, **alloc, **need, *work, *finish, *safe;


list<int>* pt;

int gc = 0;

void computeVars(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = mx[i][j] - alloc[i][j];
            std::cout<<need[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}

void allc(){
pt = new list<int>[n];
    avail = new int[m];
    work = new int[n];
    finish = new int[n];
    safe = new int[n];
    mx = new int*[n];
    need = new int*[n];
    alloc = new int*[n];
    for(int i=0; i<n; i++){
        mx[i] = new int[m];
        need[i] = new int[m];
        alloc[i] = new int[m];
    }
}

int fin_check(){
    for(int i=0; i<n; i++)
        if(finish[i]!=1)
            return 1;
    return 0;
}

int checker(int l){
    for(int i=0; i<m; i++)
        if(need[l][i]>work[i])
            return 0;
    return 1;
}

int safety(int st){
    for(int i=0; i<m; i++)
        work[i] = avail[i];
    for(int i=0; i<n; i++)
        finish[i] = 0;
    pt[gc].empty();

    while(fin_check()){
        int count = 0;
        for(int i=st; i<n; i++){
            if(finish[i]==0 && checker(i))
            {
                for(int j=0; j<m; j++){
                    work[j] = work[j] + alloc[i][j];
                    finish[i] = 1;
                }
                pt[gc].push_back(i);
                safe[safe_count++] = i;
                break;
            }
            else
                count++;
            if(count==n)
                return 0;
        }
        for(int i=0; i<st; i++){
            if(finish[i]==0 && checker(i))
            {
                for(int j=0; j<m; j++){
                    work[j] = work[j] + alloc[i][j];
                    finish[i] = 1;
                }
                pt[gc].push_back(i);
                safe[safe_count++] = i;
                break;
            }
            else
                count++;
            if(count==n)
                return 0;
        }
        if(!fin_check()){
            cout<<"\nPattern - ";
            for(list<int>::iterator t = pt[gc].begin(); t!=pt[gc].end(); t++)
                cout<<*t<<" ";
            cout<<endl;
            gc++;
            return 1;
        }
    }

}

list<int> q;

void check(){
    int mc,imc,lc=0;
    for(int i =0; i<n; i++){
        if(pt[lc++]==q){
            cout<<"Pattern is safe";
            break;
        }
    }
}

int main()
{
    int c,t1,t2,t3,pid;
    std::cout<<"\nEnter number of processes - ";
    std::cin>>n;
    std::cout<<"\nEnter number of resources - ";
    std::cin>>m;
    allc();
    for(int i=0; i<m; i++){
        std::cout<<"\nEnter instances of resource "<<i<<" - ";
        std::cin>>avail[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cout<<"\nALLOC PID "<<i<<" RES "<<j<<" -> ";
            std::cin>>alloc[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
     std::cout<<"\nMAX PID "<<i<<" RES "<<j<<" -> ";
            std::cin>>mx[i][j];
        }
    }
    computeVars();
    for(int i=0; i<n; i++)
        cout<<"SAFETY - "<<safety(i);

    cout<<"\nEnter a sequence to check - ";
    for(int i =0; i<n; i++){
        int temp;
        cin>>temp;
        q.push_back(temp);
    }

    check();


    return 0;
}
