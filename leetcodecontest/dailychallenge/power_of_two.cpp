#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        // using property of bits that for each power of 2 its represntation is 1000 and just before it it should be 1111 so there ans would come zero
        return ((n & (n - 1)) == 0);
    }
};

int main()
{
    return 0;
}