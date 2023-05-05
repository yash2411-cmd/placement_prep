#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0)return 1;
    return n*fact(n-1);
}

// function to count digits in a number using recursion
int count(int n){
    if(n==0)return 0;
    return 1 + count(n/10);
}

int main()
{
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    // cout<<count(n)<<endl;
 return 0;
}




