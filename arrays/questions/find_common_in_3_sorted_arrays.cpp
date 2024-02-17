#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> ans;
    int p1 = 0, p2 = 0, p3 = 0;
    while (p1 < n1 && p2 < n2 && p3 < n3)
    {
        if (A[p1] == B[p2] && B[p2] == C[p3])
        {
            if (ans.empty() || ans.back() != A[p1])
            {
                ans.push_back(A[p1]);
            }
            p1++;
            p2++;
            p3++;
        }
        else if (A[p1] <= B[p2] && A[p1] <= C[p3])
        {
            p1++;
        }
        else if (B[p2] <= A[p1] && B[p2] <= C[p3])
        {
            p2++;
        }
        else
        { // C[p3] is smaller or equal
            p3++;
        }
    }
    return ans;
}

int main()
{
    return 0;
}