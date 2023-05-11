#include<bits/stdc++.h>
using namespace std;


    int myAtoi(string s) {
        int n= s.length();
        int i=0;
        while(s[i]==' '){
            i++;
        }
        double ans=0;
        bool neg= s[i]=='-';
        bool pos= s[i]=='+';
        if(neg || pos){
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            ans= ans*10 + (s[i]-'0');
            i++;
        }
        if(neg){
            ans= -1*ans;
        }
        if(ans>INT_MAX)return INT_MAX;
        if(ans<INT_MIN)return INT_MIN;
        return ans;
    }



int main()
{
    string s;
    cin>>s;
    cout<<myAtoi(s);
 return 0;
}