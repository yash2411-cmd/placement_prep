#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        long long cost = 0;
        for (int i = 0; i < n; i++)
        {
            q.push(arr[i]);
        }
        while (q.size() > 1)
        {
            long long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            long long sum = a + b;
            cost += sum;
            q.push(sum);
        }
        return cost;
    }
};

int main()
{
    return 0;
}