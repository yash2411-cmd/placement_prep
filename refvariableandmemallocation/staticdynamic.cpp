#include<bits/stdc++.h>
using namespace std;
int main()
{
    // static memory allocation
    int arr[10];

    // dynamic memory allocation in heap
    int n;
    cin >> n;
    int *arr2 = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<"sum of array is: "<<sum<<endl; 

 return 0;
}