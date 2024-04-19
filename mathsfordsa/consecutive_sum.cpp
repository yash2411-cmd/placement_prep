#include <bits/stdc++.h>
using namespace std;

// Intution is to find a pattern between consicutive sums, if you calculate consicutive sum of length 2
// eg -> (1 + 2 = 3), (2 + 3 = 5), (3 + 4 = 7), ...
// it is an ap with common diff = 2 and first term = 3

// similarly for length 3
// eg -> (1 + 2 + 3 = 6), (2 + 3 + 4 = 9), (3 + 4 + 5 = 12),....
// it is an ap with common diff = 3 and first term = 6.
// Similarly we can calculate for other terms too.

// approach
// So for solving the problem we can find first term(a) and common diff(d) of each length using loop till a<=n and use an answer and if (n -a) % (d) == 0 then we will increment the answer i.e. ans++.
// And that answer will represent how many lengths can have consecutuve integers as sum n.

class Solution
{
public:
    // time compelexity is O(n) and space is constant
    int consecutiveNumbersSum(int n)
    {
        int ans = 0;
        int term = 0, diff = 0;
        if (n == 1)
            return 1;
        for (int i = 1; i < n; i++)
        {
            term += i;
            diff++;
            if ((n - term) < 0)
            {
                break;
            }
            if ((n - term) % diff == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}