#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity for this solution is O(mlogn) where m is the size of order and n is the size of string since we are using sort function
    string customSortString(string order, string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++)
        {
            char ch = order[i];
            mp[ch] = i;
        }
        auto cmp = [&](char a, char b)
        {
            return mp[a] < mp[b];
        };
        sort(s.begin(), s.end(), cmp);
        return s;
    }

    // for this function the time complexity  is linear that is O(n+m) since we are only iterating on both strings
    string customSortString(string order, string s)
    {
        unordered_map<char, int> mp;
        for (auto ch : s)
        {
            mp[ch]++;
        }
        string ans;
        for (auto ch : order)
        {
            if (mp.find(ch) != mp.end())
            {
                ans += string(mp[ch], ch);
                mp.erase(ch);
            }
        }
        for (auto i : mp)
        {
            ans += string(i.second, i.first);
        }
        return ans;
    }
};

int main()
{
    return 0;
}