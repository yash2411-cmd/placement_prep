#include <bits/stdc++.h> 
using namespace std; 

void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i=0;i<n-1;i++){
        int mnindex= i;
        for(int j=i+1;j<n;j++){
            if(arr[mnindex]>arr[j]){
                mnindex=j;
            }
        }
        swap(arr[mnindex],arr[i]);
    }
}

int main(){
    vector<int>v={1,9,5,6,42,2};
    selectionSort(v,v.size());
    cout<<"array after selection sort: ";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}