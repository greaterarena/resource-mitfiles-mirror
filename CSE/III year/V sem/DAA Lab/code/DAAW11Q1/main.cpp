#include <iostream>
using namespace std;

int size;

int  *v, *e, *vold;

void del(int *arr, int key){
	for(int i=0;i<size;i++){
		if(arr[i]==key)
			arr[i]=-1;
	}
}

int empty(int *arr){
	for(int i=0;i<size;i++)
		if(arr[i]!=-1)
			return 0;
	return 1;
}

void findmin(int *arr, int *x, int *y){
    int i;
	for(i=0;i<size;i++){
		if(vold[i]!=-1){
		    //if(arr[i]);
			if(arr[i]<(*y)){
				*x=i;
				*y=arr[i];
			}
		}
	}

}
void prim(int **cost,int start){
	int j,x=100,y=100,k=0;
	v[0]=start;
	del(vold,start);
	while(!empty(vold)){
		j=0;
		x=100,y=100;
		while(j<=k){
            findmin(cost[v[j]],&x,&y);
            j++;
		}
		e[k]=y;v[++k]=x;
		del(vold,x);
	}
}

int main(){
	cout<<"vertices: ";
	cin>>size;
	vold = new int[size];
	v = new int[size];
	e = new int[size-1];
	int **cost = new int*[size];
	for(int i=0;i<size;i++)
        vold[i]=i;
	cout<<"\ncost:\n";
	for(int i=0;i<size;i++){
		cost[i]=new int[size];
		cout<<i<<": ";
		for(int j=0;j<size;j++)
			cin>>cost[i][j];
	}
	int start;
	cout<<"\n enter start: ";
	cin>>start;
	prim(cost,start);
	cout<<"\n vertices: ";
	for(int i=0;i<size;i++)
		cout<<v[i]<<" ";

	cout<<"\n edges: ";
	for(int i=0;i<size-1;i++)
		cout<<e[i]<<" ";

	return 0;
}
