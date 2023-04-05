#include<bits/stdc++.h>
using namespace std;


int main(){
    // again this is not the most optimized way to solve this problem it has t.c n^3 which is brute force approach
    int arr[5]= {1,2,3,4,10};
    int sum = 17;
    vector<int>ans;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++)
            if(arr[i]+arr[j]+arr[k]==sum){
                ans.push_back(min(arr[i],arr[j]));
                ans.push_back(max(arr[i],arr[j]));
                ans.push_back(arr[k]);

            }
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}