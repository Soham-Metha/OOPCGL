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
        cout<<"\033[44m";
        cout<<"\nTitle : "<<title;
        cout<<"\nPrice : "<<price;
        cout<<"\n\033[0m";
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
        cout<<"\033[44m";
        cout<<"page count : "<<pageC;
        cout<<"\n\033[0m";
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
        cout<<"\033[44m";
        cout<<"play time : "<<playingTime;
        cout<<"\n\033[0m";
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
        if (b.price==0 || t.price==0)
        {
            throw 0;
        }
        
    }
    catch(int i)
    {
        cout<<"Error!Price cant be 0 "<<endl;
    }
    
    return 0;
}