#include<bits/stdc++.h>
using namespace std;

    int reverseint(int x) {
        long ans=0;
        int neg=0;
        if(x<0){
            neg=1;
        }
        x= abs(x);
        while(x>0){
            int digit= x%10;
            ans= (ans * 10)+digit;
            x/=10;
        }
        if(ans>INT_MAX || ans<INT_MIN){
            return 0;
        }
        if(neg){
            return ans*-1;
        }
        else{
        return int(ans);

        }
    }


int main(){
    int n;
    cin>>n;
    cout<<reverseint(n)<<endl;;
    return 0;
}