//codestudio question
#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        ans= ans^arr[i]; // we are using property of XOR to cancel out the same element like 1^1=0 so the element which is left will be the ans.
    }

    cout<<"unique element is: "<<ans<<endl;
    return 0;
}