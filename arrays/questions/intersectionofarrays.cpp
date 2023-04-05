#include<bits/stdc++.h>
using namespace std;

    void intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        vector<int>ans;
        set<int>result;
        for(int i=0;i<nums1.size();i++)mp[nums1[i]]++;
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i])!=mp.end()){
                result.insert(nums2[i]);
            }
        }
        for(auto i:result){
            cout<<i<<" ";
        }
        
        return;
    }

int main(){
    vector<int>num1={1,2,2,1};
    vector<int>num2={2,2};
    
    intersection(num1,num2);
    return 0;
}