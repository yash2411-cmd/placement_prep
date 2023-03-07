#include<bits/stdc++.h>
using namespace std;

/*
A B C 
D E F 
G H I
*/

int main(){
    int n;cin>>n;
    int i=1;
    char ch= 'A';
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<ch<<" ";
            ch+=1;
            j++;
        }
        cout<<endl;i++;
    }
}