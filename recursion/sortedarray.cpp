#include<bits/stdc++.h>
using namespace std;

bool issorted(int arr[], int n){
    // base case 
    if(n==0 or n==1)return 1;
    // if first element is greater then its not sorted
    if(arr[0]>arr[1])return false;
    else{
        // check for next elements, we increase the pointer to next element by arr+1 and decrement size by n-1;
        if(issorted(arr+1,n-1))return true;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    if(issorted(arr,n))cout<<"Yes";
    else cout<<"No";
 return 0;
}