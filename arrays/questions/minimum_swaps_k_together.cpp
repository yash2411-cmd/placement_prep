#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // task is to find the minimum number of swaps needed to make to make all the elements less than or equal to k together that is
    // contagious
    int minSwap(int arr[], int n, int k)
    {
        // count the valid number of elements
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                count++;
            }
        }
        // count the invalid numbers of elements  which are greater than K in the windows of size count because that is the number
        // of elements we need to swap
        int bad = 0;
        for (int i = 0; i < count; i++)
        {
            if (arr[i] > k)
            {
                bad++;
            }
        }
        // now traverse the rest of the array and find out if there are  any swaps needed or not and update the ans to minimum
        int ans = bad;
        for (int i = count; i < n; i++)
        {
            if (arr[i] > k)
                bad++;
            if (arr[i - count] > k)
                bad--;
            ans = min(ans, bad);
        }
        return ans;
    }
};

int main()
{
    return 0;
}