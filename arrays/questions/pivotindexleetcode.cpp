#include<iostream>
using namespace std;

    int pivotIndex(int nums[],int n) {
        int rightsum=0;
        for(int i=0;i<n;i++){
            rightsum+= nums[i];
        }
        int leftsum= 0;
        for(int i=0;i<n;i++){
            rightsum-= nums[i];
            if(rightsum==leftsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;

    }

    int main(){
        int arr[6]= {1,7,3,6,5,6};
        cout<<"Pivot index is: "<<pivotIndex(arr,6)<<endl;
    }