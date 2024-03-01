#include <bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n)
{
    vector<int> left(n);
    vector<int> right(n);
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(arr[i], left[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(arr[i], right[i + 1]);
    }
    long long ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int curr = min(left[i - 1], right[i + 1]);
        if (curr > arr[i])
        {
            ans += (curr - arr[i]);
        }
    }
    return ans;
}
int main()
{
    return 0;
}