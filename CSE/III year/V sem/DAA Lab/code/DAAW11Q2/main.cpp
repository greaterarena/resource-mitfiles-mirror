#include <iostream>
using namespace std;

typedef class edge{
	public:

	int v1,v2,w;
	void add(int a,int b,int c){
		v1 = a;
		v2 = b;
		w = c;
	}
	int check_cycle(int, int);
}edge;



int edge::check_cycle(int k, int n){
    if(k>=n)
        return 1;
    return 0;

}

int main(){
	int **cost;
	int i,j,n;
	cin>>n;
	cost = new int*[n];
	for(i=0;i<n;i++){
		cout<<"\n"<<i<<": ";
		cost[i]=new int[n];
		for(j=0;j<n;j++)
			cin>>cost[i][j];
	}
	edge *e;
	int esize = (n*(n-1))/2;
	e = new edge[esize];
	int k=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			e[k++].add(i,j,cost[i][j]);
		}
	}
	//sort


    edge temp;
	for(i=0;i<esize-1;i++){
		for(j=0;j<esize-i-1;j++)
			if(e[j].w>e[j+1].w){
                    temp = e[j];
                    e[j] = e[j+1];
                    e[j+1] = temp;
			}
	}
    cout<<endl;
    for(i=0;i<esize;i++)
        cout<<e[i].w<<" ";
    cout<<endl;
	//construct
	edge *stree = new edge[n-1];
	k=0;
	int *visited = new int[n];
	int nov=0;
	for(i=0;i<n;i++)visited[i]=0;
	for(i=0;i<esize;i++){
            nov=0;
            visited[e[i].v1]++;
            visited[e[i].v2]++;
            for(j=0;j<n;j++)
                if(visited[j]>0)
                    nov++;
			if(!e[i].check_cycle(k+1,nov)){
					stree[k++].add(e[i].v1,e[i].v2,e[i].w);
			}
			else{
            visited[e[i].v1]--;
            visited[e[i].v2]--;
			}
        if(k>n-2)
            break;
	}
	cout<<"\nmst:\nv1 v2 weight\n";
	for(i=0;i<k;i++){
		cout<<stree[i].v1<<" "<<stree[i].v2<<" "<<stree[i].w<<endl;
	}

	return 0;
}

