#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> arr,int k, int mid){
    int cowcount=1;
    int lastpos= arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]-lastpos>=mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            lastpos= arr[i];
        }
    }
    return false;
}
int aggressive(vector<int> &stalls, int k) {
  sort(stalls.begin(),stalls.end());
  int s = 0;
  int maxi = -1;
  for (int i = 0; i < stalls.size(); i++){
      if(stalls[i]>maxi){
          maxi=stalls[i];
      }
  }
  int ans=-1;
  int e= maxi;
  int mid= s+ (e-s)/2;
  while(s<=e){
      if(ispossible(stalls,k,mid)){
          ans= mid;
          s= mid+1;
      }
      else{
          e= mid-1;
      }
      mid= s+ (e-s)/2;
  }
  return ans;

}

int main(){
    vector<int> v= {4,2,1,3,6};
    int k= 2;
    cout<<aggressive(v,k)<<endl;
    return 0;
}