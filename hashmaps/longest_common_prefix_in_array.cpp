#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<string> prefixes;

        // Store all possible prefixes of elements in arr1 into the HashSet
        for (int num : arr1)
        {
            string numStr = to_string(num);
            string prefix = "";
            for (char ch : numStr)
            {
                prefix += ch;
                prefixes.insert(prefix);
            }
        }

        int maxCommonLen = 0;

        // Check all possible prefixes of elements in arr2 and find the maximum common length
        for (int num : arr2)
        {
            string numStr = to_string(num);
            string prefix = "";
            for (char ch : numStr)
            {
                prefix += ch;
                if (prefixes.find(prefix) != prefixes.end())
                {
                    maxCommonLen = max(maxCommonLen, static_cast<int>(prefix.size()));
                }
                else
                {
                    break; // No need to check further if prefix is not found
                }
            }
        }

        return maxCommonLen;
    }
};

int main()
{
    return 0;
}