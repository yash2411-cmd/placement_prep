#include<iostream>
using namespace std;

int main(){
    int n=5;
    int a=1;
        while(n>a){
            a= (a*2)+1;// finding the binary which has all setbits like 1111...
        }
        cout<<(n^a)<<endl; // we know that n xor to 1111... is equal to ~n

    return 0;
}