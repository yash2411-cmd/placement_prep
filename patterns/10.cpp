#include<bits/stdc++.h>
using namespace std;

/* 
A 
B B
C C C
*/
int main(){
    int n;cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            char ch= 'A'+i-1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;i++;
    }
}