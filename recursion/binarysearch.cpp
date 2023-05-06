#include<bits/stdc++.h>
using namespace std;

bool binary(int arr[],int s,int e,int key){
    if(s>e)return false;
    int mid= s+ (e-s)/2;
    if(arr[mid]==key)return true;

    // search in right half
    if(arr[mid]<key){
        return binary(arr,mid+1,e,key);
    }
    // search in left half
    else{
        return binary(arr,s,mid-1,key);

    }
}

int main()
{
        int n;
    cin>>n;
    int arr[n];
    int key;
    cout<<"enter key: ";
    cin>>key;
    for(int i=0;i<n;i++)cin>>arr[i];
    bool ans= binary(arr,0,n,key);
    if(ans)cout<<"found"<<endl;
    else{
        cout<<"not found"<<endl;
    }
 return 0;
}