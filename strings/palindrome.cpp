#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{
    string ans;
    for(int i=0;i<s.length();i++){
        char ch= s[i];
        if(iswalnum(ch)){
            ans.push_back(tolower(ch));
        }
    }
    string com= ans;
    reverse(ans.begin(),ans.end());
    return com==ans;
}