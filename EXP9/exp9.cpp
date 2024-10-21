#include <iostream>
using namespace std;

template<typename T>
void selection(T arr[],int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i]>arr[j]) {
                T tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
};

template<typename T>
void insrt(T arr[],int len) {
    for (int i = 1; i < len; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
};

int main(){
    int arr[] = {5,4,3,2,1};
    for(auto a:arr)
        cout<<a<<" ";
    insrt(arr,5);
    for(auto a:arr)
        cout<<a<<" ";
    return 0;
}