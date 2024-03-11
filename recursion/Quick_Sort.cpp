#include <bits/stdc++.h>
using namespace std;
#define ll long long

int Quick(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// divide and conqure alorithm
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = Quick(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void lucifer()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
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