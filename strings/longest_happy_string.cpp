#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans = "";
        int n = a + b + c;
        int cnta = 0, cntb = 0, cntc = 0;
        for (int i = 0; i < n; i++)
        {
            if ((a >= b && a >= c && cnta != 2) or (a > 0 && (cntb == 2 or cntc == 2)))
            {
                ans += 'a';
                cnta++;
                a--;
                cntb = 0;
                cntc = 0;
            }
            else if ((b >= a && b >= c && cntb != 2) or (b > 0 && (cnta == 2 or cntc == 2)))
            {
                ans += 'b';
                cntb++;
                b--;
                cnta = 0;
                cntc = 0;
            }
            if ((c >= b && c >= a && cntc != 2) or (c > 0 && (cntb == 2 or cnta == 2)))
            {
                ans += 'c';
                cntc++;
                c--;
                cntb = 0;
                cnta = 0;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}