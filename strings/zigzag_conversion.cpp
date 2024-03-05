#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<string> row(numRows);
        if (numRows == 1 || numRows > s.size())
        {
            return s;
        }
        int curr = 0;
        int dir = 1;

        for (char ch : s)
        {
            row[curr] += ch;
            if (curr == 0)
            {
                dir = 1;
            }
            else if (curr == numRows - 1)
            {
                dir = -1;
            }
            curr += dir;
        }
        string ans;
        for (auto i : row)
        {
            ans += i;
        }
        return ans;
    }
};

int main()
{
    return 0;
}