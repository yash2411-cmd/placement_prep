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
                end= mid; // in this case we know that our answer can be on second line or it can be the peak of mountain
                // so if we update end by mid-1; we can land in the first line where the answer is not present thats why we are updating the end to mid.
            }
        
            mid = start+ (end-start)/2;
        }
        return start;
    
    }

int main(){
    int arr[4] = {0,2,1,0};
    cout<<"peak of the mountain is at index: "<<peakIndexInMountainArray(arr,4)<<endl;
}