// leetcode
#include<bits/stdc++.h>
using namespace std;
    
int peakIndexInMountainArray(int arr[],int n) {
    int start= 0;
    int end= n-1;
    int mid = start+ (end-start)/2;

    while(start<end){
            if(arr[mid]<arr[mid+1]){
                start= mid+1;
            }
            else{
                end= mid;
            }
        
            mid = start+ (end-start)/2;
        }
        return start;
    
    }

int main(){
    int arr[4] = {0,2,1,0};
    cout<<"peak of the mountain is at index: "<<peakIndexInMountainArray(arr,4)<<endl;
}