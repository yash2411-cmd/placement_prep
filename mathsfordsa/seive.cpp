#include<bits/stdc++.h>
using namespace std;

// this algo is used to find the number of prime numbers from 2 to n;
int countprime(int n){
    int count=0;
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;

    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;

            for(int j=2*i;j<n;j+=i){
                prime[j]=false;
            }
        }
    }
    cout<<count;
}

int main()
{
    int n;
    cin>>n;
    countprime(n);

 return 0;
}