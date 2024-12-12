#include<GL/glut.h>
#define MAX 100
using namespace std;

struct Vector3{
    float x,y,z;
    Vector3(float a=0,float b=0,float c=0):x(a),y(b),z(c){};

    Vector3 operator*(float f)   { return Vector3( x*f   , y*f   , z*f   ); }
    Vector3 operator+(Vector3 o) { return Vector3( x+o.x , y+o.y , z+o.z ); }
    Vector3 operator-(Vector3 o) { return Vector3( x-o.x , y-o.y , z-o.z ); }
};

Vector3 lerp(Vector3 A, Vector3 B, float t) {
    return A + (B-A)*t;
};

Vector3 ball[] = {    
    Vector3( -0.9,  0.0, 0),                     // control points for sun's path
    Vector3(  0.0,  1.0, 0),
    Vector3(  0.9,  0.0, 0) 
};

Vector3 P = ball[0];                             //starting co-ord

void update(int val){
    float t = static_cast<float>(val%MAX)/MAX;
    
    Vector3 a,b;
    a = lerp(ball[0],ball[1],t);
    b = lerp(ball[1],ball[2],t);

    P = lerp(a,b,t);

    glutPostRedisplay();
    glutTimerFunc(50, update, val + 1);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.7, 0.8, 0.9, 1.0); //Light blue RGB
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    
    glColor3f(1.0, 0.6, 0.0);  // Yellow RGB
    glTranslatef(P.x, P.y, P.z);
    glutSolidSphere(0.05, 30, 30);

    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char**argv){
    glutInit(&argc,argv);

    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Ball sine wave Transition");

    glutDisplayFunc(display);

    glutTimerFunc(20, update, 0);
    glutMainLoop();
}