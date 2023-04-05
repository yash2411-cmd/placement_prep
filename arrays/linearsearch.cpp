#include<bits/stdc++.h>
using namespace std;

//time complexity is O(n) for linear search
bool linearsearch(int arr[],int n){
    int key;
    cout<<"enter the value of key: ";
    cin>>key;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}


int main(){
    int arr[5]={1,2,3,4,5};
    // check if 8 is present or not
    bool found= linearsearch(arr,5);
    if(found){
        cout<<"Key is present in array"<<endl;
    }
    else{
        cout<<"Key is not present in array"<<endl;
    }
    return 0;

}