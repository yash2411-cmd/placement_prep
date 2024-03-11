#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> ans;

bool printSubsequence(vector<int> &sub, int sum, int index, int n, int target, vector<int> &arr)
{
    if (index == n)
    {
        if (sum == target)
        {
            for (auto i : sub)
                cout << i << " ";
            return true;
        }

        else
        {
            return false;
        }
    }

    // Taking the current element
    sub.push_back(arr[index]);
    sum += arr[index];
    bool take = printSubsequence(sub, sum, index + 1, n, target, arr);
    if (take)
    {
        return true;
    }
    // Not taking the current element
    sub.pop_back();
    sum -= arr[index];
    bool nottake = printSubsequence(sub, sum, index + 1, n, target, arr);
    if (nottake)
        return true;
    return false;
}

void lucifer()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> sub;
    printSubsequence(sub, 0, 0, n, sum, arr);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// online submission
#endif

    // main program starts

    ll t;
    cin >> t;
    while (t--)
    {
        lucifer();
    }
    return 0;
}