#include <iostream>
using namespace std;
int *visited;

int findmin(int *a, int n){

    int minval = a[0];
    int pos=0;
    for(int i=0;i<n;i++)
        if(a[i]>minval){
            minval = a[i];
            pos = i;
        }
    for(int i=1;i<n;i++)
        if(!visited[i]&&a[i]<minval){
            minval = a[i];
            pos = i;
        }
    return pos;
}

void djikstra(int **cost,int source,int n){
    int *shd = new int[n];
    visited = new int[n];
    int i,j,temp;
    for(i=0;i<n;i++){
        shd[i]=cost[source][i];
        visited[i]=0;
    }
    visited[source] = 1;
    while(1){
        temp = findmin(shd,n);
        for(i=0;i<n;i++){
            if(shd[i]>shd[temp]+cost[temp][i])
                shd[i]=shd[temp]+cost[temp][i];
        }
        visited[temp]=1;
        for(i=0;i<n;i++)
            if(visited[i]==0)
                break;
        if(i==n)
            break;
    }
    cout<<"\nsingle source shortest path:\n";
    for(i=0;i<n;i++){
        cout<<source<<'-'<<i<<": "<<shd[i]<<endl;
    }
}

int main(){
	int **cost;
	int i,j,n;
	cout<<"enter no. of vertices: ";
	cin>>n;
	visited = new int[n];
	cost = new int*[n];
	cout<<"enter cost:\n";
	for(i=0;i<n;i++){
		cout<<"\n"<<i<<": ";
		visited[i]=0;
		cost[i]=new int[n];
		for(j=0;j<n;j++)
			cin>>cost[i][j];
	}


	int source;

	cout<<"Enter source: ";
	cin>>source;

	djikstra(cost,source,n);
	return 0;
}
