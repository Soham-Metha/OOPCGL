#include<GL/glut.h>
using namespace std;

template<typename T> struct Vector3{
    T x,y,z;
    Vector3():x(0),y(0),z(0){};
    Vector3(T a,T b,T c):x(a),y(b),z(c){};

    Vector3<T> operator*(float f) {
        T a = x*f;
        T b = y*f;
        T c = z*f;
        return Vector3<T>( a , b , c );
    }

    Vector3<T> operator+(Vector3<T> other) {
        T a = x+other.x;
        T b = y+other.y;
        T c = z+other.z;
        return Vector3<T>( a , b , c );
    }

    Vector3<T> operator-(Vector3<T> other) {
        T a = x-other.x;
        T b = y-other.y;
        T c = z-other.z;
        return Vector3<T>( a , b , c );
    }
};

Vector3<float> bounds[] = {    
    Vector3<float>( -1.0,  0.5, 0),
    Vector3<float>(  1.0,  0.5, 0),
    Vector3<float>(  1.0, -0.5, 0),  
    Vector3<float>( -1.0, -0.5, 0),
};

Vector3<float>  
    o(   1.0, 0.6, 0.0), //orange
    y(   1.0, 0.7, 0.1), //yellow
    lB(  0.7, 0.8, 0.9), //light blue
    dB(  0.0, 0.2, 0.3), //dark blue
    lBr( 0.5, 0.3, 0.0), //light brown
    dBr( 0.3, 0.2, 0.1); //dark brown

template<typename T>
T lerp(T A, T B, float t) {
    return A + (B-A)*t;   //return B*t + A*(1-t);
};

template <typename T>
T helper(T a, T b, T c, float t) {
    T ab = lerp(a,b,t);
    T bc = lerp(b,c,t);
    return lerp(ab,bc,t);
}

template <typename T>
T helper(T a, T b, T c, T d, float t) {
    T abc = helper(a,b,c,t);
    T bcd = helper(b,c,d,t);
    return lerp(abc,bcd,t);
}

template <typename T>
T helper(T a,T b,T c, T d, T e, float t) {
    T abcd = helper(a,b,c,d,t);
    T bcde = helper(b,c,d,e,t);
    return lerp(abcd,bcde,t);
}

void drawBounds(Vector3<float> bg) {
    glBegin(GL_POLYGON);
    glColor3f(bg.x, bg.y, bg.z);
    for (int i = 0; i < 4; i++)
        glVertex3f(bounds[i].x,bounds[i].y,-1.4);
    glEnd();
}