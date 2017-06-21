#include <iostream>
#include <GL/glut.h>

using namespace std;

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320,320,-240,240);
}

void geodraw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    //LINE
    glBegin(GL_LINES);
        glVertex2i(-300,10);
        glVertex2i(-100,150);
    glEnd();
    //Polygon
    glBegin(GL_POLYGON);
        glVertex2i(10,10);
        glVertex2i(10,230);
        glVertex2i(300,230);
        glVertex2i(300,10);
    glEnd();
    //Home
    glBegin(GL_LINE_LOOP);
        glVertex2i(-230,-80);
        glVertex2i(-120,-10);
        glVertex2i(-20,-80);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(-230,-80);
        glVertex2i(-230,-200);
        glVertex2i(-20,-200);
        glVertex2i(-20,-80);
    glEnd();
    //door frame
    glBegin(GL_LINE_LOOP);
        glVertex2i(-90,-200);
        glVertex2i(-90,-140);
        glVertex2i(-150,-140);
        glVertex2i(-150,-200);
    glEnd();
    //doors
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
        glVertex2i(-150,-140);
        glVertex2i(-130,-150);
        glVertex2i(-130,-190);
        glVertex2i(-150,-200);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(-90,-140);
        glVertex2i(-110,-150);
        glVertex2i(-110,-190);
        glVertex2i(-90,-200);
    glEnd();
    //window 1 & 2
    glBegin(GL_LINE_LOOP);
        glVertex2i(-150,-90);
        glVertex2i(-150,-130);
        glVertex2i(-200,-130);
        glVertex2i(-200,-90);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(-90,-90);
        glVertex2i(-90,-130);
        glVertex2i(-40,-130);
        glVertex2i(-40,-90);
    glEnd();
    //window doors 1
    glBegin(GL_POLYGON);
        glVertex2i(-150,-90);
        glVertex2i(-165,-95);
        glVertex2i(-165,-125);
        glVertex2i(-150,-130);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(-200,-90);
        glVertex2i(-185,-95);
        glVertex2i(-185,-125);
        glVertex2i(-200,-130);
    glEnd();
    //window doors 2
    glBegin(GL_POLYGON);
        glVertex2i(-40,-90);
        glVertex2i(-55,-95);
        glVertex2i(-55,-125);
        glVertex2i(-40,-130);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(-90,-90);
        glVertex2i(-75,-95);
        glVertex2i(-75,-125);
        glVertex2i(-90,-130);
    glEnd();
    //polygon
    glBegin(GL_POLYGON);
        glVertex2i(87,-108);
        glVertex2i(100,-70);
        glVertex2i(140,-70);
        glVertex2i(153,-108);
        glVertex2i(120,-140);
    glEnd();
    //ploygon legs
    glBegin(GL_POLYGON);
        glVertex2i(100,-70);
        glVertex2i(140,-70);
        glVertex2i(120,-10);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(140,-70);
        glVertex2i(153,-108);
        glVertex2i(203,-70);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(87,-108);
        glVertex2i(100,-70);
        glVertex2i(37,-70);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(153,-108);
        glVertex2i(120,-140);
        glVertex2i(174,-175);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(87,-108);
        glVertex2i(120,-140);
        glVertex2i(66,-175);
    glEnd();
    glFlush();
}

void launcher(int a,int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Many Amaze Very GL WOW");
    glutDisplayFunc(geodraw);
    switch(a){
        case 0: glutDisplayFunc(geodraw);break;
        default: glutDisplayFunc(geodraw);break;
    }
    init();
    glutMainLoop();
}

int main(int argc, char** argv){
    int choice;
    cout<<"\nWow Launcher Much Amaze\n1. Hello World\n2. Basic Geometry\n3. Basic Incremental Line drawing Many WOW\n4. Exit\nEnter choice - ";
    cin>>choice;
    switch(choice){
        case 1: cout<<"\nHello, World\n";break;
        case 2: cout<<"\nLaunching now\n";launcher(0,argc,argv);break;
        case 3: cout<<"\nInitiatng BIL Algorithm\n";break;
        case 4: return 0;
        default: cout<<"\nInvalid Option\n";break;
    }
    return 0;
}
