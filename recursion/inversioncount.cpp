#include<bits/stdc++.h>
using namespace std;

int merge(int *arr,int s,int e){
    int mid= s+(e-s)/2;
    int n1=mid-s+1;
    int n2= e-mid;
    int inv_cnt=0;

    int first[n1];
    int second[n2];

    // copy first array
    int k=s;
    for(int i=0;i<n1;i++){
        first[i]=arr[k++];
    }
    // copy second array
    k= mid+1;
    for(int i=0;i<n2;i++){
        second[i]=arr[k++];
    }


    // this is the same logic for merge two sorted arrays
    int i=0,j=0;
    k=s;
    while(i<n1 && j<n2){
        if(first[i]<second[j]){
            arr[k++]=first[i++];
        }
        else{
            arr[k++]=second[j++];
            inv_cnt++;
        }
    }
    while(i<n1){
        arr[k++]=first[i++];
    }
    while(j<n2){
        arr[k++]=second[j++];
    }
    return inv_cnt;
}

int mergeSort(int *arr, int s, int e){
    int inv_count=0;
    if(s>=e){
        return inv_count;
    }
    int mid = s+ (e-s)/2;
    // left part 
    inv_count+= mergeSort(arr, s, mid);
    // right part
    inv_count+= mergeSort(arr, mid+1, e);

    inv_count+= merge(arr,s,e);

    // return inv_count;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int inversioncount = mergeSort(arr,0,n-1);
    cout<<"inversion count in the given array is: "<<inversioncount<<endl;

 return 0;
}