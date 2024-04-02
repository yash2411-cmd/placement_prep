#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp;
        unordered_map<char, bool> pp;
        if (s.size() != t.size())
            return false;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            if (mp.find(c1) != mp.end() && mp[c1] != c2)
            {
                return false;
            }
            if (mp.find(c1) == mp.end() && pp[c2])
            {
                return false;
            }
            mp[c1] = c2;
            pp[c2] = true;
        }
        return true;
    }
};

int main()
{
    return 0;
}