#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int skips = 0;
        int skipt = 0;
        while (i >= 0 || j >= 0)
        {

            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skips++;
                    i--;
                }
                else if (skips > 0)
                {
                    skips--;
                    i--;
                }
                else
                {
                    break;
                }
            }
            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skipt++;
                    j--;
                }
                else if (skipt > 0)
                {
                    skipt--;
                    j--;
                }
                else
                {
                    break;
                }
            }
            if (i >= 0 && j >= 0 && s[i] != t[j])
            {
                return false;
            }
            if ((i >= 0) != (j >= 0))
            {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};

int main()
{
    return 0;
}