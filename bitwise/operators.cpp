#include<iostream>
using namespace std;

int main(){
    int a=4; // 100
    int b=6; // 110

    cout<<"a&b "<<(a&b)<<endl; // 100&110= 100=4
    cout<<"a|b "<<(a|b)<<endl; // 100|110= 110= 6
    cout<<"~a "<<(~a)<<endl; // ~100= 1111111111011= 1's compliment = 00000000000100= 2's compliment = -0000000000101= -5
    cout<<"a^b "<<(a^b)<<endl; // 100^110= 010= 2

    return 0;

}