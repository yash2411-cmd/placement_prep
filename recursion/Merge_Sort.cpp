#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int l = low;
    int r = mid + 1;

    while (l <= mid && r <= high)
    {
        if (arr[l] <= arr[r])
        {
            temp.push_back(arr[l]);
            l++;
        }
        else
        {
            temp.push_back(arr[r]);
            r++;
        }
    }

    while (l <= mid)
    {
        temp.push_back(arr[l]);
        l++;
    }
    while (r <= high)
    {
        temp.push_back(arr[r]);
        r++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// online submission
#endif

    // main program starts
    vector<int> arr = {5, 4, 3, 2, 1};
    mergeSort(arr, 0, 4);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}