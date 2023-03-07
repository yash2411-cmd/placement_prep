#include<bits/stdc++.h>
using namespace std;

/*
A A A 
B B B
C C C

formula= 'A' + i - 1
*/
int main(){
    int n;cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch= 'A'+i-1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}