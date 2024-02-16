#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }

    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(int arr[], int s, int e)
{
    int inv_count = 0;
    int temp[e + 1];
    if (e > s)
    {
        int mid = (s + e) / 2;

        // left part
        inv_count += mergeSort(arr, s, mid);
        // right part
        inv_count += mergeSort(arr, mid + 1, e);

        inv_count += merge(arr, temp, s, mid + 1, e);
    }
    return inv_count;
    // return inv_count;
}

// for large inputs
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long low, long long mid, long long high)
    {
        long long ans = 0;
        int k = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (k <= high && arr[i] > arr[k])
                k++;
            ans += (k - (mid + 1));
        }
        long long left = low;
        long long right = mid + 1;
        vector<long long> temp;
        while (left <= mid && right <= high)
        {
            if (arr[left] < arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return ans;
    }
    long long mergesort(long long arr[], long long low, long long high)
    {
        long long ans = 0;
        if (low >= high)
            return 0;
        long long mid = low + (high - low) / 2;
        ans = mergesort(arr, low, mid);
        ans += mergesort(arr, mid + 1, high);
        ans += merge(arr, low, mid, high);
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr, 0, N - 1);
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int inversioncount = mergeSort(arr, 0, n - 1);
    cout << "inversion count in the given array is: " << inversioncount << endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    return 0;
}