#include <bits/stdc++.h>
using namespace std;

static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}
// Function to find the maximum profit and the number of jobs done.
// time complexity is O(nlog n *k)
// we can do this in better complexity by using disjoint set
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);
    int maxdeadline = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxdeadline = max(maxdeadline, arr[i].dead);
    }

    int count = 0;
    int ans = 0;
    vector<int> schedule(maxdeadline + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int currp = arr[i].profit;
        int currid = arr[i].id;
        int currdead = arr[i].dead;

        for (int k = currdead; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                ans += currp;
                count++;
                schedule[k] = currid;
                break;
            }
        }
    }
    return {count, ans};
}

int main()
{
    return 0;
}