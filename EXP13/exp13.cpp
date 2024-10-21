#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string,int> m;
    m["a"] = 1;
    m["b"] = 12;
    m["c"] = 123;
    m["d"] = 23;
    cout<<m["d"];
    return 0;
}