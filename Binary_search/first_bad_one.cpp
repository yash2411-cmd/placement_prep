#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int st = 1;
        int end = n;
        int ans = 0;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (isBadVersion(mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}