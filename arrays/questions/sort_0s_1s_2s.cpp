#include <bits/stdc++.h>
using namespace std;

// Dutch National Flag algorithm:  commonly used for sorting an array of 0s, 1s, and 2s.

class Solution
{
public:
public:
    void sort012(int a[], int n)
    {
        int i = 0;
        int mid = 0;
        int j = n - 1;
        while (mid <= j)
        {
            if (a[mid] == 0)
            {
                swap(a[i], a[mid]);
                i++;
                mid++;
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(a[mid], a[j]);
                j--;
            }
        }
    }
};

int main()
{
    return 0;
}