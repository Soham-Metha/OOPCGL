#include "helpers.cpp"
#define MAX 100
using namespace std;

//-------------------------------------------------------------------DATA VALUES---------------------------------------------------------------------------------

Vector3<float> ball[] = {    
    Vector3<float>( -0.9,  0.0, 0),                     // co ords for ball's path
    Vector3<float>( -0.4,  1.0, 0),
    Vector3<float>(  0.0,  0.0, 0),
    Vector3<float>(  0.4, -1.0, 0), 
    Vector3<float>(  0.9,  0.0, 0) 
};

Vector3<float> P = ball[0], fg = o, bg = dB;         //starting co-ord, ball color and bg color

//--------------------------------------------------------------FUNCTION DEFINITION-----------------------------------------------------------------------------

void drawBall() {
    glColor3f(fg.x, fg.y, fg.z);
    glTranslatef(P.x, P.y, -1.4);
    glutSolidSphere(0.05, 30, 30);
}

//------------------------------------------------------------OPENGL CALLBACK FUNCTIONS---------------------------------------------------------------------------

void update(int val){
    float t = static_cast<float>(val%MAX)/MAX;
    P = helper(ball[0],ball[1],ball[2],ball[3],ball[4],t);         
    fg = helper(o,y,o,t);
    bg = helper(dB,lB,dB,t);

    glutPostRedisplay();
    glutTimerFunc(50, update, val + 1);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double aspect = (double)w/(double)h;
    gluPerspective(45, aspect, 0.1, 200);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    
    drawBounds(bg);
    drawBall();

    glPopMatrix();
    glutSwapBuffers();
}

//----------------------------------------------------------------------MAIN-------------------------------------------------------------------------------------

int main(int argc, char**argv){
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Sunrise Sunset Transition");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
    glutMainLoop();
}