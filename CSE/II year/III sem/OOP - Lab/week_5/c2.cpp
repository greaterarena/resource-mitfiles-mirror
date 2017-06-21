#include<iostream>
using namespace std;
class circle;
class rectangle{
        int dim[3];
        friend class circle;
    public:
        void input(){
            cout<<"\ninput - L B -> ";
            cin>>dim[0]>>dim[1];
            dim[2] = dim[0] * dim[1];
        }
        void display(){
        cout<<"\nDimensions ->\n\tlength -> "<<dim[0]<<"\n\tbreadth -> "<<dim[1]<<"\nArea -> "<<dim[2];
        }
};
class circle{
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
        void larger(rectangle a){
            if(a.dim[2]>area){cout<<"\n\narea of rectangle is greater than the area of the circle\n";}
            else{cout<<"\n\narea of circle is greater than the area of the rectangle\n";}
        }
};

int main(){
    cout<<"Friend Functions - II\n";
    rectangle r;
    circle c;
    r.input();
    c.input();
    r.display();
    c.display();
    c.larger(r);
    return 0;
}
