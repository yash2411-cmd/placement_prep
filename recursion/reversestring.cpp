#include<bits/stdc++.h>
using namespace std;

void rev(string &s,int st,int en){
    if(st>en)return;
    swap(s[st],s[en]);
    rev(s,st+1,en-1);
}



int main()
{
    string s;
    cin>>s;
    int n=s.size();
    rev(s,0,n-1);
    cout<<s;
 return 0;
}