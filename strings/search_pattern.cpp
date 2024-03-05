#include <bits/stdc++.h>
using namespace std;
vector<int> search(string pattern, string text)
{
    vector<int> ans;
    for (int i = 0; i <= text.size() - pattern.size(); i++)
    {
        if (text.substr(i, pattern.length()) == pattern)
        {
            ans.push_back(i + 1);
        }
    }

    return ans;
}

int main()
{
    return 0;
}