#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubStr(string str)
    {
        stack<int> s;
        int cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (!s.empty())
            {
                if (s.top() != str[i])
                {
                    s.pop();
                    if (s.empty())
                    {
                        cnt++;
                    }
                }
                else
                {
                    s.push(str[i]);
                }
            }
            else
            {
                s.push(str[i]);
            }
        }
        if (s.size() == 0)
        {
            return cnt;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    return 0;
}