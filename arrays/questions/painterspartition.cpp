#include<bits/stdc++.h>
using namespace std;

// this problem is exactly same as the book allocation problem on codestudio.
bool ispossible(vector<int>arr, int n,int m, int mid){
    int paintercount=1;
    int blocksum=0;
    for(int i=0;i<n;i++){
        if(blocksum+arr[i]<=mid){
            blocksum+=arr[i];
        }
        else{
            paintercount++;
            if(paintercount>m || arr[i]>mid){
                return false;
            }
            blocksum= arr[i];
        }
    }
    return true;
} 

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n = boards.size();
    int s=0;
    int sum=0;
    for(auto i:boards){
        sum+=i;
    }
    int e=sum;
    int ans=-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(ispossible(boards,n,k,mid)){
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