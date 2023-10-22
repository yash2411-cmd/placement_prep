#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        vector<int> v;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                v.push_back(i);
            }
        }
        if (v.size() < k)
        {
            return "";
        }
        else
        {
            int sh = INT_MAX;
            vector<string> solution;
            for (int i = k - 1; i < v.size(); i++)
            {
                if (sh == v[i] - v[i - k + 1] + 1)
                {
                    solution.push_back(s.substr(v[i - k + 1], sh));
                }
                else if (sh > v[i] - v[i - k + 1] + 1)
                {
                    solution.clear();
                    sh = v[i] - v[i - k + 1] + 1;
                    solution.push_back(s.substr(v[i - k + 1], sh));
                }
            }
            return *min_element(solution.begin(), solution.end());
        }
    }
};
int main()
{
    return 0;
}