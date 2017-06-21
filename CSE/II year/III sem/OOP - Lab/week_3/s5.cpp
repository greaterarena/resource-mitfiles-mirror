#include<iostream>

using namespace std;


int computearea(int r)
{  return 3.14*r*r; }
int computearea(int a, int b)
{return a*b;}
float computearea(float a, float b)
{ return (0.5*a*b); }


int main()
{ 
    cout<<"\ninput radius base height length width -> ";
    int r, l, t;
    float b, h;
    cin>>r>>b>>h>>l>>t;
    cout<<"\narea circle ->"<<computearea(r)<<"\n";
    cout<<"\narea rectangle ->"<<computearea(l,t)<<"\n";
    cout<<"\narea triangle ->"<<computearea(b,h)<<"\n\n";
    return 0;
}

