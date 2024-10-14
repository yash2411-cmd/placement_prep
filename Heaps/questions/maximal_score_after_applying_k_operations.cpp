#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            int mx = pq.top();
            pq.pop();

            ans+= mx;
            pq.push(ceil(mx/3.0));
        }
        // cout<<endl;
        return ans;
    }
};

int main()
{
 return 0;
}