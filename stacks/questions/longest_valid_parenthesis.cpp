#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1); // Initialize the stack with a dummy index

        int maxLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i); // Push the index of the opening parenthesis
            }
            else
            {
                st.pop(); // Pop the last element (index of matching opening parenthesis)

                if (!st.empty())
                {
                    // Update the length with the difference between the current index and the new top of the stack
                    maxLen = max(maxLen, i - st.top());
                }
                else
                {
                    // If the stack is empty, push the current index to mark the start of a new potential valid substring
                    st.push(i);
                }
            }
        }

        return maxLen;
    }
};

int main()
{
    return 0;
}