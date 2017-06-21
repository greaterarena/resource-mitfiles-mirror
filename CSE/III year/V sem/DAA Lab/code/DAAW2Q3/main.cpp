#include <iostream>
#include <math.h>

using namespace std;

int gcd = 1; int* sa; int gen; int xp,yp, count=0;

void inv(int fact){
    for(int t=fact; t<=gen;)
    {
        if(sa[t]%fact==0){
            sa[t]=0;
        }
        t = t + fact;
    }
}

int occ_count(int u, int d){
    int temp = 0;
    while(true){
        if(u%d==0){
            temp++;
            u = u/d;
        }
        else
            break;
    }
    return temp;
}

void sieve_gcd(){
    int main = 2;
    while(main<=gen)
    {
        if(sa[main]==0)
        {
            main++;
            continue;
        }
        else{
            count++;
            if(xp%sa[main]==0&&yp%sa[main]==0)
            {
                int xocc = occ_count(xp,sa[main]); int yocc = occ_count(yp,sa[main]);
                int occfact = min(xocc,yocc);
                gcd *= pow(sa[main],occfact);
            }
            inv(sa[main]);
            main++;
        }
    }
    cout<<"\nGCD - "<<xp<<", "<<yp<<" -> "<<gcd<<" "<< count;
}

void gen_sieve(int x, int y){
    xp = x; yp = y;
    gen = min(x,y);
    sa = new int[gen+1];
    for(int i=0;i<=gen;i++){
        sa[i] = i;
    }
    sieve_gcd();
}

int main()
{
    cout<<"Sieve\n";
    gen_sieve(10717789, 10297789);
    return 0;
}
