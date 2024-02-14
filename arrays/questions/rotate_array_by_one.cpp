#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < n - 1)
    {
        swap(arr[i], arr[j]);
        i++;
    }
}

int main()
{
    return 0;
}