#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int clumsy(int n)
    {
        stack<int> st;
        st.push(n);
        int time = 1;
        for (int i = n - 1; i >= 1; i--)
        {
            int x = st.top();
            if (time == 1)
            {
                st.pop();
                st.push(x * i);
                time = 2;
                continue;
            }
            else if (time == 2)
            {
                st.pop();
                st.push(x / i);
                time = 3;
                continue;
            }
            else if (time == 3)
            {
                st.pop();
                st.push(x + i);
                time = 4;
                continue;
            }
            else if (time == 4)
            {
                st.push(-1 * i);
                time = 1;
            }
        }
        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}