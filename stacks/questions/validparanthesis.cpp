#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{' or s[i]=='(' or s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.size()==0)return false;
                if(s[i]=='}' & st.top()!='{')return false;
                if(s[i]==')' & st.top()!='(')return false;
                if(s[i]==']' & st.top()!='[')return false;
                st.pop();
            }
        }
        if(st.size()>0)return false;
        else{
            return true;
        }
    }
};


int main()
{
 return 0;
}