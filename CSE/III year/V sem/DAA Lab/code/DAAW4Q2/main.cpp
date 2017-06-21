#include <iostream>
#include <stdlib.h>

using namespace std;

int cities = 8;
int** dist, *permute, pcount = 1;
int *res = new int[cities]; int cost=0; int cost_max,flag=0;

void randomizer(){
    dist = new int*[cities];
    for(int i=0;i<cities;i++)
        dist[i] = new int[cities];
    for(int i=0;i<cities;i++)
        for(int j=0;j<cities;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else if(j>i)
                dist[i][j] = rand()%100 + 1;
            else
                dist[i][j] = dist[j][i];
        }
}



void costy(int* x){
    for(int i=0; i<cities-1; i++)
    {
        cost += dist[x[i]-1][x[i+1]-1];
    }
    cost += dist[x[0]-1][x[cities-1]-1];
    //cout<<" - "<<cost<<endl;
    if(flag==0){
        cost_max = cost;
        flag++;
    }
    if(cost<cost_max){
        cost_max = cost;
        for (int i = 0; i < cities; i++)
            res[i]=permute[i];
    }
    cost = 0;
}

int next(int v[], int n) {
    int i = n - 1;
    v[i] = v[i] + 1;
    while ((i >= 0) && (v[i] > n)) {
        v[i] = 1;
        i--;
        if(i >= 0)
            v[i]++;
    }

    if (i < 0)
        return 0;
    return 1;
}

void printv(int n) {
    //for (int i = 0; i < n; i++)
    //    cout<<permute[i];
    costy(permute);
}

int is_perm(int v[], int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (v[i] == v[j])
                return 0;

    return 1;
}

void permute_gen(){
    permute = new int[cities];

    for(int i = 0; i < cities; i++)
    {
        permute[i] = i+1;
        res[i] = i+1;
    }

    //for (int i = 0; i < cities; i++)
    //    cout<<permute[i];
    costy(res);
    while (next(permute,cities))
        if (is_perm(permute,cities))
            printv(cities);
}

void display(int c)
{
    if(c==0){
        for(int i=0;i<cities;i++)
            {
                for(int j=0;j<cities;j++)
                    cout<<dist[i][j]<<" ";
                cout<<endl;
            }
    }
    if(c==1){
       cout<<"\nShotest Path - ";
       for (int i = 0; i < cities; i++)
            cout<<res[i]<<" ";
        cout<<" COST - "<<cost_max;
    }
}

int main()
{
    randomizer();
    display(0);
    permute_gen();
    display(1);
    return 0;
}
