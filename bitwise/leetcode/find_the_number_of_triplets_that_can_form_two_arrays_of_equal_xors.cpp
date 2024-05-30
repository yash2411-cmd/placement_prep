#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int xor_sum = 0;
            for (int k = i; k < n; ++k)
            {
                xor_sum ^= arr[k];
                if (xor_sum == 0 && k > i)
                {
                    ans += (k - i);
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}