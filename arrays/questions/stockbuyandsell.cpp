#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left =0;
        int right = 1;
        int maxprofit=0;
        int currprofit;
        while(right < prices.size()){
            currprofit= prices[right] - prices[left];
            if(prices[left]<prices[right]){
                maxprofit = max(currprofit, maxprofit);
            }
            else{
                left = right;
            }
            right++;
        }
        return maxprofit;
    }
};

int main()
{
 return 0;
}