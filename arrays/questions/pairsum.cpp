#include<bits/stdc++.h>
using namespace std;


int main(){
    // time complexity nearly equals to n^2 this is not the optimized solution
    int arr[5]= {1,2,3,4,15};
    int sum = 17;
    vector<int>ans;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]+arr[j]==sum){
                ans.push_back(min(arr[i],arr[j]));
                ans.push_back(max(arr[i],arr[j]));
            }
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}