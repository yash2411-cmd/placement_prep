#include <bits/stdc++.h>
using namespace std;

// To solve this problem, we can use a priority queue (min heap) to keep track of the smallest difference between heights encountered so far. we'll use ladders for the largest differences and bricks for the rest.
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<int> minheap;
        for (int i = 0; i < heights.size() - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
            {
                minheap.push(-diff);
                if (minheap.size() > ladders)
                {
                    bricks += minheap.top();
                    minheap.pop();
                }
                if (bricks < 0)
                {
                    return i;
                }
            }
        }
        return heights.size() - 1;
    }
};

int main()
{
    return 0;
}