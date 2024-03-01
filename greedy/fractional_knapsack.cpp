#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<double, Item> a, pair<double, Item> b)
{
    return a.first > b.first;
}
// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, Item>> v;
    for (int i = 0; i < n; i++)
    {
        double perunit = (1.0 * arr[i].value) / arr[i].weight;
        pair<double, Item> p = make_pair(perunit, arr[i]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);

    double total = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second.weight > W)
        {
            // only can take fraction
            total += W * v[i].first;
            W = 0;
        }
        else
        {
            // full value
            total += v[i].second.value;
            W = W - v[i].second.weight;
        }
    }
    return total;
}
int main()
{
    return 0;
}