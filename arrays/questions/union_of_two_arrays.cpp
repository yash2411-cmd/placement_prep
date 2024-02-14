#include <bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)
{
    set<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ans.insert(b[i]);
    }
    return ans.size();
}

int main()
{
    return 0;
}