#include <bits/stdc++.h>
// code studio 
// this is a most important question it uses binary search and has been asked many times in faang
using namespace std;
bool ispossible(vector<int>arr, int n,int m, int mid){
    int studentcount=1;
    int pagesum=0;
    for(int i=0;i<n;i++){
        if(pagesum+arr[i]<=mid){
            pagesum+=arr[i];
        }
        else{
            studentcount++;
            if(studentcount>m || arr[i]>mid){
                return false;
            }
            pagesum= arr[i];
        }
    }
    return true;
} 
int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
    int s=0;
    int sum=0;
    for(auto i:arr){
        sum+=i;
    }
    int e=sum;
    int ans=-1;
    int mid= s+(e-s)/2;
    if(n<m)return ans;
    while(s<=e){
        if(ispossible(arr,n,m,mid)){
            ans= mid;
            e= mid-1;
        }
        else{
            s= mid+1;

        }
        mid= s+(e-s)/2;

    }
    return ans;
}

int main(){
    vector<int>v;
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<allocateBooks(v,n,m);
}