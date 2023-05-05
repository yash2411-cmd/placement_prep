#include<bits/stdc++.h>
using namespace std;
int power(int n){
    if(n==0)return 1;
    return 2*power(n-1);
}

void print(int n){
    if(n==0)return;
    cout<<n<<endl;
    // // tail recurion 
    print(n-1);

    // head recursion
    // print(n-1);
    // cout<<n<<endl;
}

int main()
{
    int n;
    cin>>n;
    cout<<power(n)<<endl;
    print(n);
 return 0;
}