#include<iostream>
using namespace std;
#define col 10
#define row 10

class matrix{
		int r;
		int c;
		int arr[row][col];
	public:
		matrix(int rc,int cc,int dat[][col]){	
			r = rc;
			c = cc;	
			int i, j;
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					arr[i][j]=dat[i][j];			
		}
		matrix(const matrix &y){
			r = y.r;
			c = y.c;
			int i,j;
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					arr[i][j]=y.arr[i][j];
		}
		void diag(){
			cout<<"\n\n principal diagonal elements ->";
			if(r!=c){cout<<"\n not possible need square matrix\n";}
			else{
			int i;
			for(i=0;i<r;i++)
				cout<<" "<<arr[i][i];				
			cout<<"\n";	}
		}
		void sort(){
			int i,j,k,n,temp;
			n = c;
			for(k=0;k<r;k++)
			for(j=0;j<n-1;j++)
			for(i=n-1;i>0;i--)
			if(arr[k][i]<arr[k][i-1])
			{
				temp=arr[k][i];
				arr[k][i]=arr[k][i-1];
				arr[k][i-1]=temp;
			}

			for(i=0;i<r;i++){
				for(j=0;j<c;j++)
					cout<<" "<<arr[i][j];
			}
			cout<<endl;
		}

};

int main(){
	cout<<endl<<"enter r and c ->";
	int re,ce,i,j;
	cin>>re>>ce;
	int wer[re][col];
	for(i=0;i<re;i++)
		for(j=0;j<ce;j++){cout<<"\n "<<i<<" "<<j<<" ->";
			cin>>wer[i][j];}
	matrix b(re,ce,wer);
	matrix c(b);
	b.diag();
	b.sort();
	c.diag();
	c.sort();
	return 0;
} 


