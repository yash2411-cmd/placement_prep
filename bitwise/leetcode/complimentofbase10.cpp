#include<iostream>
using namespace std;

int main(){
// first way of solving 
    // int n=5;
    // int a=1;
    //     while(n>a){
    //         a= (a*2)+1;// finding the binary which has all setbits like 1111...
    //     }
    //     cout<<(n^a)<<endl; // we know that n xor to 1111... is equal to ~n
// second way of solving 

    int n;
    cin>>n;
    int m= n;
    if(n==0){ // base case we know ~0 is equal to 1
        cout<<1<<endl;
        return 0;
    }
    int mask=0;
    while(m!=0){
        mask = (mask << 1) | 1; // here we will get 00000000....00111;
        m= (m >> 1); // so after 3 iterations m will become zero then we will exit the loop with mask value of 111;
    }
    int ans;
    ans= (~n)&mask; // we know xor property so we will xor not of n and mask to get the n's compliment 
    cout<<ans<<endl;

    return 0;
}