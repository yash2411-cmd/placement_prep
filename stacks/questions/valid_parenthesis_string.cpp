#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //   time and space complexity both are O(n)
    bool checkValidString(string s)
    {
        stack<int> st;
        stack<int> star;
        // int star = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == '*')
            {
                star.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else if (!star.empty())
                {
                    star.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while (!st.empty())
        {
            if (star.empty() || st.top() > star.top())
            {
                return false;
            }
            st.pop();
            star.pop();
        }
        return true;
    }
};

int main()
{
    return 0;
}