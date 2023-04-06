#include<bits/stdc++.h>
using namespace std;
// t.c in binary search is O(logn)
int binarysearch(int arr[],int size, int key){
    int start=0;
    int end= size-1;
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

int main(){
    int even[8]= {1,2,3,4,5,6,7,8};
    int odd[7]= {2,5,6,7,8,9,12};

    int evenind= binarysearch(even,8,7);
    cout<<"the index at which 7 is present is: "<< evenind<<endl;
    int oddind= binarysearch(odd,7,6);
    cout<<"the index at which 6 is present is: "<< oddind<<endl;
    return 0;

}