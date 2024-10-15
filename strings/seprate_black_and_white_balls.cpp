#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumSteps(string s)
    {

        long long ans = 0;

        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                cnt++;
            }
            else
            {
                ans += cnt;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}