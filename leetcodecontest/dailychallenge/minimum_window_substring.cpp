#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        if (t == "")
        {
            return "";
        }
        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        // initializing the count t map because it's not gonna change
        for (auto ch : t)
        {
            countT[ch]++;
        }

        int have = 0;
        int need = countT.size();
        pair<int, int> res = {-1, -1};
        int reslen = INT_MAX;
        int l = 0;
        int ri;

        for (int r = 0; r < n; r++)
        {
            char ch = s[r];
            window[ch]++;

            if (countT.find(ch) != countT.end() && window[ch] == countT[ch])
            {
                have++;
            }

            while (have == need)
            {
                if ((r - l + 1) < reslen)
                {
                    res.first = l;
                    res.second = r;
                    reslen = r - l + 1;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (countT.find(leftChar) != countT.end() && window[leftChar] < countT[leftChar])
                {
                    have--;
                }

                l++;
            }
        }

        l = res.first;
        ri = res.second;

        if (l == -1 || ri == -1)
        {
            return "";
        }

        return s.substr(l, reslen);
    }
};

int main()
{
    return 0;
}