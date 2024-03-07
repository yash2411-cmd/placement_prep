#include <bits/stdc++.h>
using namespace std;
#define ll long long

// KMP ALGORITHM FOR FINDING PATTERN IN A GIVING STRING TIME COMPLEXITY IS O(N+M)
// WHERE N AND M ARE SIZES OF TEXT AND PATTERN RESPECTIVELY

vector<int> prefix_function(string s)
{
    vector<int> ans(s.size());
    for (int i = 1; i < s.size(); i++)
    {
        int j = ans[i - 1];
        // while we don't have a matching character and j is greater than zero check for the previous characters
        while (j > 0 && s[i] != s[j])
        {
            j = ans[j - 1];
        }
        // found a new match incrememt the j pointer and add it to the ans
        if (s[i] == s[j])
        {
            j++;
        }
        ans[i] = j;
    }
    return ans;
}

void lucifer()
{
    string text, pattern;
    cin >> text >> pattern;
    // creating the prefix of pattern
    vector<int> prefix = prefix_function(pattern);

    int i = 0;
    // j pointer tells us how many charaters are matched
    int j = 0;
    int pos = -1;
    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            j++;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = prefix[j - 1];
            }
            else
            {
                i++;
            }
        }
        // if we have reached at the end of pattern than we have found a match
        if (j == pattern.size())
        {
            // store the index at which string is found
            pos = i - pattern.size();
            break;
        }
    }
    cout << "pattern found at index: " << pos << endl;
}

int main()
{
    lucifer();
    return 0;
}