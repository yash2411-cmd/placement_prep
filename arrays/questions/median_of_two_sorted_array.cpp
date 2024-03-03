#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 0)
    {
        int one = v[n / 2];
        int two = v[(n / 2) - 1];
        return (one + two) / 2;
    }
    else
    {
        return v[n / 2];
    }
}

int main()
{
    return 0;
}