#include <iostream>
using namespace std;
class Publication {
    public:
    string title;
    float price;
    void getInfo(){
        cout<<"Enter Title : ";
        cin>>title;
        cout<<"Enter price : ";
        cin>>price;
    }
    void dispInfo(){
        cout<<"\nTitle : "<<title;
        cout<<"\nPrice : "<<price;
    }
};
class Book : public Publication {
    public:
    int pageC;

    void getInfo(){
        Publication::getInfo();
        cout<<"Enter page count : ";
        cin>>pageC;
    }
    void dispInfo(){
        Publication::dispInfo();
        cout<<"page count : "<<pageC;
    }
};
class Tape : public Publication {
    public:
    float playingTime;

    void getInfo(){
        Publication::getInfo();
        cout<<"Enter play time : ";
        cin>>playingTime;
    }
    void dispInfo(){
        Publication::dispInfo();
        cout<<"play time : "<<playingTime;
    }
};

int main(){
    try
    {
        Book b;
        Tape t;
        b.getInfo();
        t.getInfo();
        b.dispInfo();
        t.dispInfo();
        if (b.price<0 || t.price<0)
        {
            throw 0;
        }
        
    }
    catch(int i)
    {
        cout<<"Error!Price cant be negative "<<endl;
    }
    
    return 0;
}