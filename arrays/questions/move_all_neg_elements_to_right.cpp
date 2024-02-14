#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void segregateElements(int arr[], int n)
    {
        vector<int> neg;
        vector<int> full;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                neg.push_back(arr[i]);
            }
            else
            {
                full.push_back(arr[i]);
            }
        }
        for (int i = 0; i < neg.size(); i++)
        {
            full.push_back(neg[i]);
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = full[i];
        }
    }
};

int main()
{
    return 0;
}