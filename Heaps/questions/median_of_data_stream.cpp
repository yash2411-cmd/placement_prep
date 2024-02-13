#include <bits/stdc++.h>
using namespace std;

// leetcode solution
class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.empty() || num <= maxheap.top())
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }

        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() == minheap.size())
        {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        else
        {
            return maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// codestudio solution:
// #include <bits/stdc++.h>
int signum(int a, int b)

{

    if (a == b)

        return 0;

    else if (a < b)

        return -1;

    else

        return 1;
}
void median(int ele, priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int &m)
{
    switch (signum(maxheap.size(), minheap.size()))
    {
    case 0:
        if (ele > m)
        {
            minheap.push(ele);
            m = minheap.top();
        }
        else
        {
            maxheap.push(ele);
            m = maxheap.top();
        }
        break;
    case 1:
        if (ele > m)
        {
            minheap.push(ele);
            m = (maxheap.top() + minheap.top()) / 2;
        }
        else
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(ele);
            m = (maxheap.top() + minheap.top()) / 2;
        }
        break;
    case -1:
        if (ele > m)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(ele);
            m = (maxheap.top() + minheap.top()) / 2;
        }
        else
        {
            maxheap.push(ele);
            m = (maxheap.top() + minheap.top()) / 2;
        }
        break;
    }
    // return;
}

vector<int> findMedian(vector<int> &arr, int n)
{

    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    vector<int> ans;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        median(ele, maxheap, minheap, m);
        ans.push_back(m);
    }
    return ans;
}

int main()
{
    return 0;
}