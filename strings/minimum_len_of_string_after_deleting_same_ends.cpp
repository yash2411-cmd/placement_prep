#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        if (s.size() == 1)
        {
            return 1;
        }
        while (i < j && s[i] == s[j])
        {
            char temp = s[i];
            while (i <= j && s[i] == temp)
            {
                i++;
            }
            while (j > i && s[j] == temp)
            {
                j--;
            }
        }
        return j - i + 1;
    }
};
int main()
{
    return 0;
}