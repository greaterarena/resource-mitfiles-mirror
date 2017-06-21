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
		matrix()
		{
            r = 0;
            c = 0;
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
			cout<<"\n\nprincipal diagonal elements ->";
			if(r!=c){cout<<"\nnot possible need square matrix\n";}
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

		matrix operator+(matrix y)
		{
		    matrix z;
		    if(r != y.r || c != y.c)
            {
                    cout<<"\nThe matrices cannot be added\n";
                    return z;
            }
            else
            {
                z.r = r;
                z.c = c;
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    z.arr[i][j]=arr[i][j]+y.arr[i][j];
                }
                return z;
            }
		}

        matrix operator-(matrix y)
		{
		    matrix z;
		    if(r != y.r || c != y.c)
            {
                    cout<<"\nThe matrices cannot be added\n";
                    return z;
            }
            else
            {
                z.r = r;
                z.c = c;
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    z.arr[i][j]=arr[i][j]-y.arr[i][j];
                }
                return z;
            }

		}

		friend ostream & operator << (ostream &,const matrix &);

		friend istream & operator >> (istream & ,matrix &);

};

ostream & operator << (ostream & customout, const matrix & y)
{
	int r = y.r;
	int c = y.c;
	int i,j;
	customout<<"\nPrinting array Now ->\n\n";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			customout<<y.arr[i][j]<<"\t";
		}
		customout<<endl;
	}
	customout<<endl;
	return customout;
}

istream & operator >> (istream & in, matrix & y)
{
	int i,j;
	cout<<endl<<"enter r and c ->";
	in>>y.r>>y.c;
	for(i=0;i<y.r;i++)
		for(j=0;j<y.c;j++){cout<<"\n "<<i<<" "<<j<<" ->";
			in>>y.arr[i][j];}
	return in;
}


int main(){
	matrix b;
	cin>>b;
	matrix c;
	cin>>c;
	cout<<b<<c;
	b.diag();
	b.sort();
	c.diag();
	c.sort();
	matrix a = b+c;
    cout<<"\nAddition - \n";
	cout<<a;
	matrix d = b-c;
	cout<<"\nSubtraction - \n";
	cout<<d;
	return 0;
}


