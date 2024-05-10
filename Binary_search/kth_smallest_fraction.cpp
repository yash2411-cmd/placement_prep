#include <bits/stdc++.h>
using namespace std;

// brute force approach O(n^2)

class Solution
{
public:
    static bool cmp(const pair<double, pair<int, int>> &a,
                    const pair<double, pair<int, int>> &b)
    {
        return a.first < b.first;
    }

    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        vector<pair<double, pair<int, int>>> fractions;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (i < j)
                {
                    fractions.push_back(
                        {(double)arr[i] / arr[j], {arr[i], arr[j]}});
                }
            }
        }

        sort(fractions.begin(), fractions.end(), cmp);
        for (auto i : fractions)
        {
            cout << i.second.first << " " << i.second.second << " ";
        }
        cout << endl;
        if (fractions.empty())
        {
            return {};
        }

        // If k is larger than or equal to the size of fractions, return the last fraction
        if (k >= fractions.size())
        {
            return {fractions.back().second.first, fractions.back().second.second};
        }

        return {fractions[k - 1].second.first, fractions[k - 1].second.second};
    }
};

// optimized solution using binary search time compleixty is O(nlogn)
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();
        double left = 0, right = 1;
        int p = 1, q = 1; // Initialize numerator and denominator
        while (left <= right)
        {
            double mid = left + (right - left) / 2;
            int count = 0;
            double mx = 0;
            // p = 0, q = 1; // Reset p and q for each iteration
            for (int i = 0, j = 1; i < n; ++i)
            {
                while (j < n && arr[i] > mid * arr[j])
                    j++;
                count += n - j;
                if (j < n && mx <= ((arr[i] * 1.0) / arr[j]))
                {
                    p = arr[i];
                    q = arr[j];
                    mx = ((arr[i] * 1.0) / arr[j]);
                }
            }
            if (count == k)
            {
                break;
            }
            if (count > k)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return {p, q};
    }
};

int main()
{
    return 0;
}