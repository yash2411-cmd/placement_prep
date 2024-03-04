#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int i = 0;
        int j = tokens.size() - 1;

        while (i <= j)
        {
            if (power >= tokens[i])
            {
                score += 1;
                power -= tokens[i];
                i++;
            }
            else if (score > 0 && i < j)
            {
                score -= 1;
                power += tokens[j];
                j--;
            }
            else
            {
                return score;
            }
        }
        return score;
    }
};

int main()
{
    return 0;
}