#include<iostream>
#include<vector>

using namespace std;
struct Person{
    string name;
    int dob;
    public:
    Person(){};
    Person(string nm,int d):name(nm),dob(d){};
};

int main(){
    vector<Person> v;
    v.push_back(Person("a",10));
    return 0;
}