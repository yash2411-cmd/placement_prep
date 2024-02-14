#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {

        // greedy approach
        if (n <= 1)
        {
            return 0;
        }
        if (arr[0] == 0)
        {
            return -1;
        }
        int maxreach = 0;
        int jump = 0;
        int step = 0;

        for (int i = 0; i < n - 1; i++)
        {
            maxreach = max(maxreach, arr[i] + i);
            if (i == step)
            {
                jump++;
                step = maxreach;
            }
        }
        if (step >= n - 1)
        {
            return jump;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    return 0;
}