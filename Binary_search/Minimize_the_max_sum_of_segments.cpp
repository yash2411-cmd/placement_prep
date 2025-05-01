#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[1000005];

bool chk(int x)
{
    int s = 0;
    int seg = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s + a[i] > x)
        {
            s = 0;
            seg++;
        }
        s += a[i];
    }
    return seg >= m;
}

void lucifer()
{
    cin >> n >> m;
    int sum = 0;
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
    }

    int l = maxn, r = sum;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (chk(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// online submission
#endif

    lucifer();
}