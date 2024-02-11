#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> q;
        for (int i = 0; i < k; i++)
        {
            q.push(arr[i]);
        }

        for (int i = k; i <= r; i++)
        {
            if (arr[i] < q.top())
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        int ans = q.top();
        return ans;
    }
};

int main()
{
    return 0;
}