#include<bits/stdc++.h>
using namespace std;

bool found(int arr[],int n,int key){
    if(n==0)return 0;
    if(n==1)return (key==arr[0]);
    if(key!=arr[0])return found(arr+1,n-1,key);

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
    bool ans= found(arr,n,key);
    if(ans)cout<<"found"<<endl;
    else{
        cout<<"not found"<<endl;
    }
 return 0;
}