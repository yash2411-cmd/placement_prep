#include<bits/stdc++.h>
using namespace std;

// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // initialized a candy array because we know acc to rule 1 each child should have atleast one candy
        vector<int>candy(n,1);

        // using greedy method, we traverse from left to right and check if ratings of ith position is greater from ith-1 pos if so, we update candy[i] + 1
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                candy[i]= candy[i-1]+1;
            }
        }
        // same as above loop just traversing from right to left
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                candy[i]= max(candy[i], candy[i+1]+1);
            }
        }
        
        int ans=0;
        for(auto i:candy){
            ans+= i;
        }
        return ans;
    }
};


int main()
{
 return 0;
}