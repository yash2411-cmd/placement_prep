#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int ind = 0;
        int n = word.size();
        while (true)
        {
            char c = word[ind];
            if (c == ch)
            {
                break;
            }
            if (ind == n - 1)
            {
                return word;
            }
            ind++;
        }
        reverse(word.begin(), word.begin() + ind + 1);
        return word;
    }
};

int main()
{
    return 0;
}