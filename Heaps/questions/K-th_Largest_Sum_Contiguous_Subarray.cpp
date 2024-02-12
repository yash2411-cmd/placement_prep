#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += Arr[j];
                if (q.size() < K)
                {
                    q.push(sum);
                }
                else
                {
                    if (sum > q.top())
                    {
                        q.pop();
                        q.push(sum);
                    }
                }
            }
        }

        return q.top();
    }
};

int main()
{
    return 0;
}