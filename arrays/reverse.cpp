#include<bits/stdc++.h>
using namespace std;

void printreversearray(int arr[],int n){
    cout<<"Printing the array in reverse order: ";
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

// printing array elements
void printarray(int arr[], int n){
    cout<<"Printing the array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

void revarray(int arr[],int n){
    int start= 0;
    int end= n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}


int main(){
    int arr[5]={1,2,3,4,5};
    // reversearray(arr,5);
    revarray(arr,5);
    printarray(arr,5);
    return 0;

}