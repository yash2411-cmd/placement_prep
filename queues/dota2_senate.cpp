#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexit and space complexiy is O(n)
    string predictPartyVictory(string senate)
    {
        int n = senate.length();
        int rcount = 0;
        int dcount = 0;

        queue<char> q;
        for (char ch : senate)
        {
            q.push(ch);
        }
        cout << rcount << " " << dcount << endl;
        while (q.size())
        {
            if (rcount > q.size())
                return "Radiant";
            if (dcount > q.size())
                return "Dire";
            char front = q.front();
            q.pop();
            if (front == 'R')
            {
                if (dcount > rcount)
                {
                    dcount--;
                }
                else
                {
                    rcount++;
                    q.push(front);
                }
            }
            else
            {
                if (rcount > dcount)
                {
                    rcount--;
                }
                else
                {
                    dcount++;
                    q.push(front);
                }
            }
        }
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
        cout << rcount << " " << dcount << endl;
        return "";
    }
};

int main()
{
    return 0;
}