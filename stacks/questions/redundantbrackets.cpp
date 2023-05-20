#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{

            if(ch== ')'){
                bool redundant = true;
                while(st.top()!='('){
                    char c= st.top();
                    if(c == '+' || c == '-' || c == '*'|| c == '/'){
                        redundant= false;
                    }
                    st.pop();
                }
                if(redundant== true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
