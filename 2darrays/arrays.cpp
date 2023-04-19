#include<iostream>
using namespace std;

bool search(int arr[][3], int r, int c,int target){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    // hardcore initialization
    // int arr[3][3]= {{12,2,3},{12,2,3},{12,2,3}};
    int arr[4][3];
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"printing array: "<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter a number to find in matrix: ";
    cin>>target;
    if(search(arr,4,3,target)){
        cout<<"element is present"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    cout<<endl;
}