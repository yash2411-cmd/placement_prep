#include<bits/stdc++.h>
using namespace std;

bool pali(string s,int st,int en){
    if(st>en)return 1;
    if(s[st]!=s[en])return 0;
    return pali(s,st+1,en-1);
}



int main()
{
    string s;
    cin>>s;
    int n=s.size();
    bool ans= pali(s,0,n-1);
    if(ans)cout<<"palindrome hai"<<endl;
    else cout<<"not palindrome"<<endl;
 return 0;
}