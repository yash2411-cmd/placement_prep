#include <bits/stdc++.h>
using namespace std;
#define int long long

void lucifer()
{
    int n;
    cin >> n;

    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        printf("? %lld %lld %d %lld\n", l, mid, 1, n);
        cout << flush;
        int x;
        cin >> x;
        if (x != (mid - l + 1))
            r = mid;
        else
            l = mid + 1;
    }
    int ansa = l;

    l = 1;
    r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        printf("? %d %lld %lld %lld\n", 1, n, l, mid);
        cout << flush;
        int x;
        cin >> x;
        if (x != (mid - l + 1))
            r = mid;
        else
            l = mid + 1;
    }
    int ansb = l;
    printf("! %lld %lld\n", ansa, ansb);
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