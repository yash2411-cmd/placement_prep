#include <bits/stdc++.h>
using namespace std;
// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        // vector<p>ans;
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (m.find(k - arr[i]) != m.end())
            {
                count += m[k - arr[i]];
                if ((k - arr[i]) == arr[i])
                {
                    count--;
                }
                m[arr[i]]--;
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}