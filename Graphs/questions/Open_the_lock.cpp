#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n*m) where n is the size of queue and m is the max size of string in queue which will be 4 so its O(n)
    //  space complexity will be O(n+m) where n is the queue size and m is the size for deadends
    int openLock(vector<string> &deadends, string target)
    {
        string start = "0000";
        if (start == target)
            return 0;
        unordered_set<string> s(deadends.begin(), deadends.end());
        if (s.count(start))
            return -1;
        queue<string> q;
        unordered_set<string> vis;
        vis.insert(start);
        q.push(start);
        int ans = 0;
        while (!q.empty())
        {
            int si = q.size();
            for (int i = 0; i < si; i++)
            {
                string node = q.front();
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    for (int k = -1; k <= 1; k++)
                    {
                        string next = node;
                        next[j] = ((next[j] - '0' + k + 10) % 10) + '0';
                        if (next == target)
                        {
                            return ans + 1;
                        }
                        if (!s.count(next) && !vis.count(next))
                        {
                            q.push(next);
                            vis.insert(next);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

int main()
{
    return 0;
}