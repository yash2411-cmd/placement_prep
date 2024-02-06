#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // // approach: If the character is a digit, it builds up the number (num) by multiplying the current value by 10 and adding the value of the digit.
    // If the character is a '+', it adds the current num to the result with the appropriate sign and resets num to 0, setting the sign to positive.
    // If the character is a '-', it does the same as above but sets the sign to negative.
    // If the character is '(', it recursively calls calculateExpression to evaluate the expression inside the parentheses, updating num with the result.
    // If the character is ')', it adds the current num to the result with the appropriate sign and returns the result, effectively ending the current recursive call.
    // Finally, it adds the last num to the result and returns the final result.

public:
    int calculateExpression(const string &s, int &index)
    {
        int result = 0;
        int num = 0;
        int sign = 1;

        while (index < s.length())
        {
            char ch = s[index++];
            if (isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '+')
            {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (ch == '-')
            {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (ch == '(')
            {
                num = calculateExpression(s, index);
            }
            else if (ch == ')')
            {
                result += sign * num;
                return result;
            }
        }

        result += sign * num;
        return result;
    }
    int calculate(string s)
    {
        int i = 0;
        return calculateExpression(s, i);
    }
};

int main()
{
    return 0;
}