#include<iostream>

using namespace std;

int count = 0;

int euclid(int m, int n)
{
 int r;
 while(n!=0)
 {
  r=m%n;
  m=n;
  n=r;
  cout << "a";
  count = count+1;;
 }
 return m;
}
int main()
{
 cout<<"Euclid";
 cout<<"\nGCD is: "<<euclid(10717789, 10297789)<<" "<<count;
 return 0;
}
