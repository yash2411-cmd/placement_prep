#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        long long base = 9;
        long long digit = 1;
        long long start = 1;
        while (n > base * digit)
        {
            n -= base * digit;
            base *= 10;
            digit++;
            start *= 10;
        }

        //    long long num = pow(10, digit-1) + (n+1)/digit;
        //    int index = (n-1)%digit;
        start = start + (n - 1) / digit;
        return to_string(start)[(n - 1) % digit] - '0';
    }
};

int main()
{
    return 0;
}