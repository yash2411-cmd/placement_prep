#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        if (num1.size() < num2.size())
        {
            return addStrings(num2, num1);
        }
        else
        {
            string ans = "";
            int carry = 0;
            int sum = 0;
            int i = num1.size() - 1;
            int j = num2.size() - 1;
            while (i >= 0 && j >= 0)
            {
                sum = (num1[i] - '0') + (num2[j] - '0') + carry;
                carry = sum / 10;
                int digit = sum % 10;
                ans += to_string(digit);
                i--;
                j--;
            }
            while (i >= 0)
            {
                sum = (num1[i] - '0') + carry;
                carry = sum / 10;
                int digit = sum % 10;
                ans += to_string(digit);
                i--;
            }
            if (carry != 0)
            {
                ans += to_string(carry);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};

int main()
{
    return 0;
}