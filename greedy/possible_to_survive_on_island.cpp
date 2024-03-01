#include <bits/stdc++.h>
using namespace std;
int minimumDays(int S, int N, int M)
{
    int sun = S / 7;
    int buydays = S - sun;

    int ans = 0;
    if ((S * M) % N == 0)
    {
        ans = (S * M) / N;
    }
    else
    {
        ans = (S * M) / N + 1;
    }

    if (ans <= buydays)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}
int main()
{
    return 0;
}