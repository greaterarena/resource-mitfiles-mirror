#include<iostream>
using namespace std;
class counter{
    static int c;
    public:
        static int showcount(){
        cout<<"\n Objects Created -> "<<c<<endl;
        }
        counter(){
            c++;
            showcount();
        }
};
int counter::c=0;
int main(){
    counter a;
    counter b;
    counter c;
    a.showcount();
    b.showcount();
    c.showcount();
    return 0;
}
