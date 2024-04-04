#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        stack<char> st;
        int ans = 0;
        int curr = 0;
        for (auto ch : s)
        {
            if (ch == '(')
            {
                st.push(ch);
                curr = st.size();
                ans = max(ans, curr);
            }
            else if (ch == ')')
            {
                st.pop();
                curr = st.size();
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}