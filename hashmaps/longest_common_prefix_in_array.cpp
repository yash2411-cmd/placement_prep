#include <bits/stdc++.h>
using namespace std;

// You are given two arrays with positive integers arr1 and arr2.

// A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.
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