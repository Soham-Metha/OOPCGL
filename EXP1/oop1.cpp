#include <iostream>
using namespace std;
class Complex{
    float real;
    float img;
    public:
    Complex(){real=0;img=0;}
    
    friend istream &operator>>(istream &ip,Complex &c)
    {
        cout<<"enter real part:"<<endl;
        ip>>c.real;
        cout<<"enter imaginary part:"<<endl;
        ip>>c.img;
    }

    Complex operator+(Complex);
    Complex operator*(Complex);
    
    friend ostream &operator<<(ostream &op,Complex &c)
    {
        if(c.img>=0)
            cout<<c.real<<" +"<<c.img<<"i";
        else
            cout<<c.real<<" "<<c.img<<"i";
    }
};
Complex Complex::operator+(Complex c)
{
        Complex t;
        t.real=real+c.real;
        t.img=img+c.img;
        return t;
}

Complex Complex::operator*(Complex c)
{
    Complex t;
    t.real=(real*c.real)-(img*c.img);
    t.img=(real*c.img)+(img*c.real);
    return t;
}

int main()
{
    Complex C,C1,C2,C3;
    cout<<"Default constructor:"<<C<<endl;
    cout<<"Enter Number 1:"<<endl;
    cin>>C1;
    cout<<"Enter number 2:"<<endl;
    cin>>C2;
    cout<<"Number 1:"<<C1<<endl;
    cout<<"Number 2:"<<C2<<endl;
    cout<<"Addition of two numbers:"<<endl;
    C3=C1+C2;
    cout<<C3<<endl;
    cout<<"Mulitplication of two numbers:"<<endl;
    C3=C1*C2;
    cout<<C3<<endl;
    return 0;
}