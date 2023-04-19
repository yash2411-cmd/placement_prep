#include<bits/stdc++.h>
using namespace std;

// bool search(int arr[][3], int r, int c,int target){
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//             if(arr[i][j]==target){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main(){
    // hardcore initialization
    // int arr[3][3]= {{12,2,3},{12,2,3},{12,2,3}};
    int arr[4][3];
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    // row wise sum
    for(int i=0;i<4;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+= arr[i][j];
        }
        cout<<"sum of row "<<i<<" is: "<<sum<<endl;
        
    }
    // column wise sum
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+= arr[i][j];
        }
        cout<<"sum of col "<<i<<" is: "<<sum<<endl;
        
    }
    // largest sum and its row index
    int maxi= INT_MIN;
    int rind= -1;
    for(int i=0;i<4;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+= arr[i][j];
        }
        if(sum>maxi){
            maxi= sum;
            rind= i;
        }
    }
    cout<<"maximum sum is: "<<maxi<<" at row th number "<<rind<<endl;

    cout<<endl;
}