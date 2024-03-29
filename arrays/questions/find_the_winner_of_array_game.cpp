#include <bits/stdc++.h>
using namespace std;

// time complexity is (n) and space is O(1)
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int one = arr[0];
        int wins = 0;

        int n = arr.size();
        int mx = *max_element(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
        {
            int two = arr[i];
            if (one > two)
            {
                wins++;
            }
            else
            {
                one = two;
                wins = 1;
            }
            if (wins == k || one == mx)
            {
                return one;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}