#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        string temp = "";
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                reverse(temp.begin(), temp.end());
                ans += temp;
                if (temp != "")
                {
                    ans += " ";
                }
                temp = "";
            }
            else
            {
                temp.push_back(s[i]);
            }
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        if (ans.back() == ' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};

int main()
{
    return 0;
}