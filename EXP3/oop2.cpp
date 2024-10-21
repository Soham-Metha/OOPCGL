#include <iostream>
using namespace std;
class db
{
    public:
    string Name, Class, Division, Address, Bloodg, license;
    int Rno, PhNo, DoB;
    inline void getInfo(){
        cout<<"Enter Name : ";
        cin>>Name;
        cout<<"Enter Class and Division : ";
        cin>>Class>>Division;
        cout<<"Enter PhNo : ";
        cin>>PhNo;
        cout<<"Enter DoB : ";
        cin>>DoB;
        cout<<"Enter Address : ";
        cin>>Address;
        cout<<"Enter Bloodgroup : ";
        cin>>Bloodg;
        cout<<"Enter license no. : ";
        cin>>license;
    }
    void dispInfo(){
        cout<<"\033[44m";
        cout<<Name<<endl;
        cout<<Class<<endl;
        cout<<Division<<endl;
        cout<<PhNo<<endl;
        cout<<DoB<<endl;
        cout<<Address<<endl;
        cout<<Bloodg<<endl;
        cout<<license<<endl;
        cout<<"\033[0m";
    }
};

class StudentDBHandler
{
    public:
    friend db;
    db d;
    static int Rollno;
    StudentDBHandler();
    ~StudentDBHandler();
    static int getRollNo(){
        return StudentDBHandler::Rollno++;
    }
    StudentDBHandler(const StudentDBHandler& s){
        this->d.Name = s.d.Name;
        this->d.Class = s.d.Class;
        this->d.Division = s.d.Division;
        this->d.Address = s.d.Address;
        this->d.Bloodg = s.d.Bloodg;
        this->d.license = s.d.license;
        this->Rollno = s.Rollno;
        this->d.PhNo = s.d.PhNo;
        this->d.DoB = s.d.DoB;
    }
};
int StudentDBHandler::Rollno=1;
StudentDBHandler::StudentDBHandler()
{
    d.getInfo();
    d.Rno=getRollNo();
}

StudentDBHandler::~StudentDBHandler()
{
    cout<<"Object Destroyed\nObject Data was : \n";
    d.dispInfo();
}

int main(){
    try
    {
        StudentDBHandler *s1;
        s1 = new StudentDBHandler();
        StudentDBHandler s2 = StudentDBHandler((*s1));

        delete s1;
    }
    catch(const exception& e)
    {
        cout <<"An Error occurred!!\n";
    }
    
    return 0;
}