#include<iostream>
using namespace std;

int main(){
    int n=234;
    int prod= 1;
    int sum=0;

    while(n>0){
        prod*=(n%10);
        sum+=(n%10);
        n/=10;
    }
    cout<<(prod-sum)<<endl;
    return 0;

}