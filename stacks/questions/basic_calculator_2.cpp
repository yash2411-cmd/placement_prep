#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        char sign = '+'; // Initial sign is positive
        int num = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            char ch = s[i];

            // If the character is a digit, build up the number
            if (isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }

            // If the character is an operator or we've reached the end of the string
            if (!isdigit(ch) && ch != ' ' || i == s.length() - 1)
            {
                // Perform operation based on the previous sign
                if (sign == '+')
                {
                    st.push(num);
                }
                else if (sign == '-')
                {
                    st.push(-num);
                }
                else if (sign == '*')
                {
                    int prev_num = st.top();
                    st.pop();
                    st.push(prev_num * num);
                }
                else if (sign == '/')
                {
                    int prev_num = st.top();
                    st.pop();
                    st.push(prev_num / num);
                }

                // Update sign and reset num
                sign = ch;
                num = 0;
            }
        }

        // Sum up all the numbers in the stack to get the final result
        int result = 0;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
int main()
{
    return 0;
}