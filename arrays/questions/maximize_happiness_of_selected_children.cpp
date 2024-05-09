#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // time complexity is O(nlogn) and space complexity is O(1)
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long ans = 0;
        long long count = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        // queue<int>q;
        // int size = 0;
        // q.push(happiness[0]);
        for (int i = 0; i < k; i++)
        {
            if (happiness[i] - i < 0)
            {
                ans += 0;
            }
            else
            {
                ans += (happiness[i] - i);
            }
        }
        cout << ans << endl;
        return ans;
    }
};

int main()
{
    return 0;
}