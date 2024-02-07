#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mapping;
        for (auto ch : s)
        {
            mapping[ch]++;
        }
        vector<pair<int, char>> free;
        for (auto i : mapping)
        {
            free.push_back({i.second, i.first});
        }
        sort(free.begin(), free.end(), greater<pair<int, char>>());
        string ans;
        for (auto [i, j] : free)
        {
            ans += string(i, j);
        }
        return ans;
    }
};

int main()
{
    return 0;
}