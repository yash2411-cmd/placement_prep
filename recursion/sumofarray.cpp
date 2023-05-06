#include<bits/stdc++.h>
using namespace std;

int sumof(int arr[],int n){
    int sum=0;
    if(n==0)return 0;
    if(n==1)return arr[0];
    
    int rem= sumof(arr+1,n-1);
    sum=arr[0]+rem;
    return sum;

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans= sumof(arr,n);
    cout<<ans<<endl;
 return 0;
}