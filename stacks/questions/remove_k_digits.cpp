#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time and space complexity both are nearly O(n)
    string removeKdigits(string s, int k)
    {
        string ans = "";
        for (auto dig : s)
        {
            while (ans.size() && ans.back() > dig && k > 0)
            {
                ans.pop_back();
                k--;
            }
            if (ans.size() || dig != '0')
            {
                ans.push_back(dig);
            }
        }
        while (k-- && ans.size())
        {
            ans.pop_back();
            // k--;
        }
        return (ans == "") ? "0" : ans;
    }
};

int main()
{
    return 0;
}