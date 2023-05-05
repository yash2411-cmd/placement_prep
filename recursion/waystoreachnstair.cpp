#include<bits/stdc++.h>
using namespace std;


// needed to be optimized using dp, will give TLE for n>35
    int climbStairs(int n) {
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        return climbStairs(n-1)+climbStairs(n-2);
    }

int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;

 return 0;
}