#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <list>

using namespace std;

int vc, rc=1;

int* visited;

list <int> stack;

int** am;

int rdm(){
    for(int i=0;i<rc;i++)
        rand();
    float t = round(rand()%1000/1000.0);
    rc++;
    return t;
}

void gen(int size){
    visited = new int[size];
    for(int i=0;i<size;i++)
        visited[i] = 0;
    am = new int*[size];
    for(int i=0;i<size;i++)
        am[i] = new int[size];
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {
            if(i==j)
            {
                am[i][j] = 0;
                continue;
            }
            else if(i<j)
                am[i][j] = rdm();
            else
                am[i][j] = am[j][i];
        }
    cout<<"\n------Adjacency Matrix------\n\n";
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            cout<<am[i][j];
        cout<<"\n";
    }
    cout<<"\n------End of Adjacency Matrix------\n";
}

void dfs(int v){
    int check=0;
    if(visited[v]!=1)
    {
        stack.push_front(v);
        visited[v] = 1;
    }
    for(int i=0; i<vc; i++){
        if(am[v][i]==1&&visited[i]==0){
            check=1;
            stack.push_front(i);
            visited[i] = 1;
        }
    }

    if(check==0){
        int el = stack.front();
        char alpha = 'A' + el;
        cout<<alpha<<" ";
        stack.pop_front();
        //return;
    }
    else
        dfs(stack.front());
        /*for(;stack.size()>0;)
        {
            int el = stack.front();
            char alpha = 'A' + el;
            cout<<alpha<<" ";
            stack.pop_front();
            dfs(el);
        }*/
}

int main()
{
    cout<<"Enter vertex count - ";
    cin>>vc;
    gen(vc);
    cout<<"\n------DFS Traversal------\n\n";
    dfs(0);
    cout<<"\n\n------DFS Traversal END------\n\n";
    return 0;
}
