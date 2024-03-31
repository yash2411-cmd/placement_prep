#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        vector<int> original;
        if (changed.size() % 2 == 1)
        {
            return {};
        }
        unordered_map<int, int> count; // Map to store element frequencies

        // Sort the changed array
        sort(changed.begin(), changed.end());

        for (int num : changed)
        {
            if (num % 2 == 0)
            {
                if (count[num / 2])
                {
                    count[num / 2]--;
                    original.push_back(num / 2);
                }
                else
                {
                    count[num]++;
                }
            }
            else
            {
                count[num]++;
            }
        }

        // Check if all pairs were found
        if (original.size() * 2 != changed.size())
        {
            return {};
        }

        return original;
    }
};

int main()
{
    return 0;
}