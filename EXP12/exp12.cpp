#include "helpers.cpp"
#define MAX 100
using namespace std;

//-------------------------------------------------------------------DATA VALUES---------------------------------------------------------------------------------

Vector3<float> sun[] = {    
    Vector3<float>( -0.9,  0.0, 0),
    Vector3<float>( -0.3,  0.5, 0),
    Vector3<float>(  0.3,  0.5, 0), 
    Vector3<float>(  0.9,  0.0, 0) 
};

Vector3<float> mtn[] = {
    Vector3<float>( -1.0, -0.5 , 0),
    Vector3<float>( -1.0, -0.25, 0),
    Vector3<float>( -0.8, -0.2 , 0),
    Vector3<float>(  1.0, -0.43, 0),
    Vector3<float>(  1.0, -0.5 , 0) 
};

Vector3<float> P = sun[0], fg = o, bg = dB;
//--------------------------------------------------------------FUNCTION DEFINITION-----------------------------------------------------------------------------

void drawSun() {
    glColor3f(fg.x, fg.y, fg.z);
    glTranslatef(P.x, P.y, -1.4);
    glutSolidSphere(0.08, 30, 30);
}

void drawMountainRange() {

    glBegin(GL_POLYGON);
    glColor3f(dBr.x,dBr.y,dBr.z);
    for (int i = 4; i >=0; i--)
        glVertex3f(-1*(mtn[i].x),mtn[i].y,-1.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(lBr.x,lBr.y,lBr.z);
    for (int i = 0; i < 5; i++)
        glVertex3f(mtn[i].x,mtn[i].y,-1.4);
    glEnd();
    
}

//------------------------------------------------------------OPENGL CALLBACK FUNCTIONS---------------------------------------------------------------------------

void update(int val){
    float t = static_cast<float>(val%MAX)/MAX;

    P = helper(sun[0],sun[1],sun[2],sun[3],t);
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
    drawMountainRange();
    drawSun();

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