#include<bits/stdc++.h>
using namespace std;

 int maxArea(vector<int>& height) {
        int ans= 0;
        int l= 0;
        int r= height.size()-1;
        while(l<r){
          int area= (r-l)*min(height[l],height[r]);
          ans= max(area,ans);
          if(height[l]<height[r]){
            l++;
          }
          else{
            r--;
          }
        }
        return ans;
    }
    int main(){
        vector<int>v= {1,8,6,2,5,4,8,3,7};
        cout<<maxArea(v)<<endl;
    }