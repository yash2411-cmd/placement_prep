#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        vector<int> freq;
        for (auto i : mp)
        {
            freq.push_back(i.second);
        }
        sort(freq.begin(), freq.end());
        int count = 0;
        for (int i = 0; i < freq.size(); i++)
        {
            count += freq[i];
            if (count > k)
            {
                return freq.size() - i;
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}