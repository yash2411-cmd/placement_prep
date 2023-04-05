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
    int arr[5];
    cout<<"first value is: "<<arr[0]<<endl;
    cout<<"fourth value is: "<<arr[4]<<endl;
    cout<<"third value is: "<<arr[3]<<endl;
    cout<<"second value is: "<<arr[2]<<endl; // gives garbage value in all locations

    // initialize the array with values
    int a[5]= {1,2,3,4,5};
    cout<<"first value is: "<<a[0]<<endl;
    cout<<"fourth value is: "<<a[4]<<endl;
    cout<<"third value is: "<<a[3]<<endl;
    cout<<"second value is: "<<a[2]<<endl; 
    printarray(a,5);
    return 0;
}