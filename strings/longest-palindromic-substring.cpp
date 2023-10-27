#include <bits/stdc++.h>
using namespace std;

int check(int i, int j, string s)
{
    int left = i;
    int right = j;
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s)
{
    if (s.empty())
    {
        return "";
    }

    int start = 0;
    int end = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int len1 = check(i, i, s);     // Odd length palindrome
        int len2 = check(i, i + 1, s); // Even length palindrome
        int len = max(len1, len2);

        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end - start + 1);
}

int main()
{
    return 0;
}