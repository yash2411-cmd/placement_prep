#include<iostream>
using namespace std;

void printarray(int arr[], int n){
    cout<<"Printing the array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i+=2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }
    printarray(arr,5);
    return 0;
}