#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // solved using KMP algorithm
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size())
            return -1;
        if (needle.size() == 0)
            return -1;
        vector<int> lps(haystack.size(), 0);
        int pre = 0;
        int suf = 1;
        int n = needle.size();
        while (suf < n)
        {
            if (needle[pre] == needle[suf])
            {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }
            else
            {
                if (pre == 0)
                {
                    lps[suf] = 0;
                    suf++;
                }
                else
                {
                    pre = lps[pre - 1];
                }
            }
        }
        pre = suf = 0;
        while (pre < haystack.size())
        {
            if (haystack[pre] == needle[suf])
            {
                pre++;
                suf++;
                if (suf == n)
                {
                    return pre - suf; // Found needle at index pre - suf
                }
            }
            else
            {
                if (suf == 0)
                {
                    pre++;
                }
                else
                {
                    suf = lps[suf - 1];
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}