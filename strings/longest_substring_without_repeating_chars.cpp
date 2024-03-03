#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_set<char> uni;

        while (j < s.size())
        {
            if (uni.find(s[j]) == uni.end())
            {
                uni.insert(s[j]);
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                uni.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}