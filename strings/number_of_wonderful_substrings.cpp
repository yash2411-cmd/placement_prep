#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long ans = 0;
        int n = word.size();
        vector<int> mp(1024, 0);
        mp[0] = 1;
        int bitmask = 0;
        for (int i = 0; i < n; i++)
        {
            int index = word[i] - 'a';
            bitmask ^= (1 << index);
            ans += mp[bitmask];
            for (int j = 0; j < 10; j++)
            {
                int oddBitmask = bitmask ^ (1 << j);
                ans += mp[oddBitmask];
            }
            mp[bitmask]++;
        }

        return ans;
    }
};

int main()
{
    return 0;
}