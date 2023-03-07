#include<bits/stdc++.h>
using namespace std;

/*
1
2 1
3 2 1
4 3 2 1
*/
int main(){
    int n;cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        int val=i;
        while(j<=i){
            cout<<val<<" ";
            val--;
            j++;
        }
        cout<<endl;
        i++;
    }
}