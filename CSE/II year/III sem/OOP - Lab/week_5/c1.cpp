#include<iostream>
using namespace std;
class circ;
class rect{
        int dim[3];
    public:
        void input(){
            cout<<"\ninput - L B -> ";
            cin>>dim[0]>>dim[1];
            dim[2] = dim[0] * dim[1];
        }
        void display(){
        cout<<"\nDimensions ->\n\tlength -> "<<dim[0]<<"\n\tbreadth -> "<<dim[1]<<"\nArea -> "<<dim[2];
        }
        friend void larger(rect, circ);
};
class circ{
        int rad;
        float area;
    public:
        void input(){
            cout<<"\ninput - R -> ";
            cin>>rad;
           area = 3.14*rad*rad;
        }
        void display(){
        cout<<"\nDimensions ->\n\tradius -> "<<rad<<"\nArea -> "<<area;
        }
        friend void larger(rect, circ);
};
void larger(rect a, circ b){
    if(a.dim[2]>b.area){cout<<"\n\narea of rectangle is greater than the area of the circle\n";}
    else{cout<<"\n\narea of circle is greater than the area of the rectangle\n";}
}

int main(){
    cout<<"Friend Functions - I\n";
    rect r;
    circ c;
    r.input();
    c.input();
    r.display();
    c.display();
    larger(r,c);
    return 0;
}
