#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n) and space is also O(n)
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    s[i] = '*';
                }
            }
        }
        while (!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }
        string ans = "";
        for (char ch : s)
        {
            if (ch != '*')
                ans.push_back(ch);
        }
        return ans;
    }
};
int main()
{
    return 0;
}