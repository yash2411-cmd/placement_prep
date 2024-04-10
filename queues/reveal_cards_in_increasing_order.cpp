#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time and space complexity is O(n)
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        vector<int> ans(deck.size());
        queue<int> pq;
        sort(deck.begin(), deck.end());
        for (int i = 0; i < deck.size(); i++)
        {
            pq.push(i);
        }
        for (int i = 0; i < deck.size(); i++)
        {
            int ind = pq.front();
            pq.pop();
            pq.push(pq.front());
            pq.pop();
            ans[ind] = deck[i];
        }
        return ans;
    }
};

int main()
{
    return 0;
}