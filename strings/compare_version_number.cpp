#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(string s)
    {
        string ans = "";
        for (auto i : s)
        {
            if (i != '.' && i != '0')
            {
                ans += i;
            }
        }
        return ans;
    }
    // time complexity is O(max(n, m)) and space is O(1);
    int compareVersion(string version1, string version2)
    {
        int n = version1.size();
        int m = version2.size();
        int left = 0;
        int right = 0;
        while (left < n || right < m)
        {
            int one = 0;
            int two = 0;
            while (left < n && version1[left] != '.')
            {
                one = one * 10 + (version1[left] - '0');
                left++;
            }
            left++;
            while (right < m && version2[right] != '.')
            {
                two = two * 10 + (version2[right] - '0');
                right++;
            }
            right++;
            if (one == 0 && one == two)
                continue;
            else if (one < two)
            {
                return -1;
            }
            else if (one > two)
            {
                return 1;
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}