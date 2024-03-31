#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int ans = 0;
        int full = numBottles;
        int empty = 0;
        while (full > 0 || empty >= numExchange)
        {
            if (full > 0)
            {
                ans += full;
                empty += full;
                full = 0;
            }
            else
            {
                empty -= numExchange;
                full++;
                numExchange++;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}