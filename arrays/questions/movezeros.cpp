#include<bits/stdc++.h>
using namespace std;

    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }

    int main(){
        vector<int>v= {0,1,0,3,12};
        moveZeroes(v);
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }