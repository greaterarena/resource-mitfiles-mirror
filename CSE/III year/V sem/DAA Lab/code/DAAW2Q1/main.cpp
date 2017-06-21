#include <iostream>

using namespace std;

int count = 0;

void consec_gcd(int x, int y){
    int gcd = 1, gcd_temp=1;
    while(gcd_temp<=x && gcd_temp<=y){
        count++;
        if(x%gcd_temp==0&&y%gcd_temp==0){
            gcd = gcd_temp;gcd_temp++;}
        else
            gcd_temp++;
    }
    cout<<"\nGCD of "<<x<<", "<<y<<" -> "<<gcd<<" "<<count;
}

int main()
{
    cout<<"Consecutive Integer\n";
    consec_gcd(10717789, 10297789);
}
