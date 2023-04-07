#include<iostream>
using namespace std;

int pivot(int arr[],int n) {
    int start= 0;
    int end= n-1;
    int mid = start+ (end-start)/2;

    while(start<end){
            if(arr[mid]>=arr[0]){ // we just need to update the start because we know that the answer is in second line so we want that start should move forward if mid is > arr[0]
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
    int arr[5]= {3,8,10,17,1};
    cout<<"pivot element is at index: "<<pivot(arr,5);
    return 0;
}