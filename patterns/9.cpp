#include<bits/stdc++.h>
using namespace std;
/*
A B C
B C D
C D E
formula: 'A'+i+j-2;
*/
int main(){
    int n;cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch= 'A'+i+j-2;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;i++;
    }
}