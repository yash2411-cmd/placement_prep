#include<bits/stdc++.h>
using namespace std;

void sumofarr(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
{
    sum+=arr[i];
}
cout<<"sum of array elements is: "<<sum<<endl;    
return;
}

void update(int arr[],int n){
    // printing array elements
    arr[0]=2411;
    cout<<"Printing the array in update function: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"going back to main function"<<endl;
    return;
}

int main(){
    int arr[5]={1,2,3,4,5};
    // int n;
    // cin>>n;
    update(arr,5);
    // printing array elements
    cout<<"Printing the array in main function: ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // calculating sum 
    sumofarr(arr,5);
    return 0;

}