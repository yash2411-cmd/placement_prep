#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// printing array elements
void printarray(int arr[], int n){
    cout<<"Printing the array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

// printing maximum and minimum of an array
void minmax(int arr[],int n){
    int mx= INT_MIN;
    int mi= INT_MAX;
    for(int i=0;i<n;i++){
        // if(arr[i]>mx){
        //     mx= arr[i];
        // }
        // if(arr[i]<mi){
        //     mi= arr[i];
        // }
        mx= max(mx,arr[i]);
        mi= min(arr[i],mi);
    }
    cout<<"minimum of array is: "<<mi<<endl;
    cout<<"maximum of array is: "<<mx<<endl;

    return;
}

void sumofarr(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
{
    sum+=arr[i];
}
cout<<"sum of array elements is: "<<sum<<endl;    
return;
}

int main(){
    int arr[10]={1,2,3,41,54,85,6,31,22,24};
    printarray(arr,10);
    int arrsize= sizeof(arr)/sizeof(int); // gives the total length of array when initialized, not depend on values.
    cout<<"Size of array is: "<<arrsize<<endl;
    minmax(arr,10);
    return 0;
}