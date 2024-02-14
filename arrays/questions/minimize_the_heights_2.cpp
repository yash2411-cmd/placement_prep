#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int diff = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++)
    {
        //   int curr = arr[i];
        //   int next = arr[i+1];
        int min_height = min(arr[0] + k, arr[i] - k);
        int max_height = max(arr[n - 1] - k, arr[i - 1] + k);
        if (min_height < 0)
        {
            continue;
        }
        diff = min(diff, max_height - min_height);
    }
    return diff;
}

int main()
{
    return 0;
}