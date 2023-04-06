#include<bits/stdc++.h>
using namespace std;


int pivotIndex(vector<int>& arr,int n) {
    int start= 0;
    int end= n-1;
    int mid = start+ (end-start)/2;

    while(start<end){
            if(arr[mid]>=arr[0]){
                start= mid+1;
            }
            else{
                end= mid;
            }
        
            mid = start+ (end-start)/2;
        }
        return start;
    
    }

int binarysearch(vector<int>& arr,int s, int e,int key){
    int start=s;
    int end= e;
    int mid= start+((end-start)/2);

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
    // going to check on right part now
        if(key>arr[mid]){
            start= mid+1;
        }
        // going to search on left part
        else{
            end= mid-1;
        }
    mid= start+((end-start)/2);

    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int pivt= pivotIndex(nums,n);
        if(target <= nums[n-1] && target>=nums[pivt]){
            return  binarysearch(nums,pivt,n-1,target);
        }
        else{
            return binarysearch(nums,0,pivt-1,target);
        }

    }

int main(){
    vector<int>arr= {4,5,6,7,0,1,2};
    int target= 0;
    cout<<"index of key is: "<<search(arr,target)<<endl;
}