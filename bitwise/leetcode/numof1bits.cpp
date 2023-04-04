#include<iostream>
using namespace std;

int main(){
    int n= 11;
    int count=0;
    while(n!=0){ // if number becomes zero, there is no need to check 
        if(n&1){ // checking if last bit is 1;
            count++; // increasing answer count
        }
        n= n>>1; // shifting one bit to right
    }
    cout<<count<<endl;
    return 0;
}