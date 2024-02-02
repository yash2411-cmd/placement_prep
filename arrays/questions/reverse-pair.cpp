#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int j = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++)
        { // checking if the solution exists for each ith element in the left part of array to jth element in the right part of array.
            while (j <= high && arr[i] > 2LL * arr[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }
        while (right <= high)
        {
            temp.push_back(arr[right++]);
        }
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int> &arr, int s, int e)
    {
        int inv_count = 0;
        // int temp[e+1];
        if (s >= e)
        {
            return 0;
        }
        int mid = (s + e) / 2;

        // left part
        inv_count += mergeSort(arr, s, mid);
        // right part
        inv_count += mergeSort(arr, mid + 1, e);

        inv_count += merge(arr, s, mid, e);
        return inv_count;
        // return inv_count;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    return 0;
}