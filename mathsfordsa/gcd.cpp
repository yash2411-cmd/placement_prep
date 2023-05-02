#include<bits/stdc++.h>
using namespace std;
// iterative approach
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while (a!=b)
    {
        if(a>b){
            a-=b;
        }
        else{
            b-=a;
        }
    }
    return a;
    
}

int main()
{
    int a;
    int b;
    cin>>a>>b;
    cout<<"GCD of given numbers is: "<<gcd(a,b);
 return 0;
}