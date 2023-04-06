// find total number of occurences of an element in an sorted array : codestudio

// codestudio problem first and last occurence of an element in sorted array
#include<bits/stdc++.h>
using namespace std;
// t.c in binary search is O(logn)
int firstocc(int arr[],int size, int key){
    int start=0;
    int end= size-1;
    int mid= start+((end-start)/2);
    int ans=-1;

    while(start<=end){
        if(arr[mid]==key){
            ans= mid;
            end= mid-1; // only change is here because we are searching for the element in left most only 
        }
    // going to check on right part now
        else if(key>arr[mid]){
            start= mid+1;
        }
        // going to search on left part
        else{
            end= mid-1;
        }
    mid= start+((end-start)/2);

    }
    return ans;
}
int lastocc(int arr[],int size, int key){
    int start=0;
    int end= size-1;
    int mid= start+((end-start)/2);
    int ans=-1;

    while(start<=end){
        if(arr[mid]==key){
            ans= mid;
            start= mid+1; // only change is here , we are moving to the right part of the array from mid.
        }
    // going to check on right part now
        else if(key>arr[mid]){
            start= mid+1;
        }
        // going to search on left part
        else{
            end= mid-1;
        }
    mid= start+((end-start)/2);

    }
    return ans;
}

int main(){
    int even[7]= {1,2,3,3,3,3,3};
    int f= firstocc(even, 7,3);
    int l= lastocc(even, 7,3);
    int ans= (l-f)+1;
    cout<<"total number of occurences of 3 in array are: "<<ans<<endl;
    // cout<<"first occurence of 3 is at index: "<<firstocc(even, 7,3)<<endl;
    // cout<<"last occurence of 3 is at index: "<<lastocc(even, 7,3)<<endl;
    
    return 0;

}