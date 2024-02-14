#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // initialize two indexs for both array
        int i = 0;
        int j = 0;
        // traverse on array one
        for (i;; i++)
        {
            // if we are at the end of the array one or array two then break out of loop
            if (i >= m + j || j >= n)
            {
                break;
            }
            // if value at nums2 index is less than we insert it after nums1 index
            if (nums1[i] >= nums2[j])
            {
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
            }
        }
        // for rest of the elements in nums2 we push them to the end of nums1
        while (j < n)
        {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
        // we make sure that no extra elements are added in nums1
        while (nums1.size() > m + n)
        {
            nums1.pop_back();
        }
    }
};

int main()
{
    return 0;
}