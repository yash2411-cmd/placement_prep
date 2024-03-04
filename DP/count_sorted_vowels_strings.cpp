#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n) and space is O(1)
    int countVowelStrings(int n)
    {
        if (n == 1)
        {
            return 5;
        }
        if (n == 2)
        {
            return 15;
        }
        int a = 5;
        int e = 4;
        int i = 3;
        int o = 2;
        int u = 1;
        for (int j = 3; j <= n; j++)
        {
            a += (e + i + o + u);
            e += (i + o + u);
            i += (o + u);
            o += (u);
            // u += (u);
        }
        return a + e + i + o + u;
    }
};

// constant time and space
class Solution
{
public:
    int countVowelStrings(int n)
        // {   we can observe that the answer will exists in this form
        int count = (n + 1) * (n + 2) * (n + 3) * (n + 4) / (4 * 3 * 2);
    return count;
}
}
;

int main()
{
    return 0;
}