#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N)
{
    vector<int> res;
    res.push_back(1);

    for (int i = 2; i <= N; i++)
    {
        int carry = 0;
        for (size_t j = 0; j < res.size(); j++)
        {
            int prod = res[j] * i + carry;
            res[j] = prod % 10; // Store the last digit of the product
            carry = prod / 10;  // Carry for the next iteration
        }
        // Add remaining carry to the result
        while (carry > 0)
        {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    return 0;
}