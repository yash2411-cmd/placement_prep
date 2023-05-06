#include<bits/stdc++.h>
using namespace std;

    bool isPowerOfThree(int n) {
        if(n<1)return false;
        if(n==1)return true;
        if(n>1){
            return n%3==0 && isPowerOfThree(n/3);
        }
        return false;
    }

int main()
{
    int n;
    cin>>n;
    cout<<isPowerOfThree(n);
 return 0;
}