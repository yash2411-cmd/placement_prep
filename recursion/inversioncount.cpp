#include<bits/stdc++.h>
using namespace std;



int merge(int arr[],int temp[],int left,int mid, int right){
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }
 
    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];
 
    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

int mergeSort(int arr[], int s, int e){
    int inv_count=0;
    int temp[e+1];
    if(e> s){
    int mid = (s+e) /2;

    // left part 
    inv_count+= mergeSort(arr, s, mid);
    // right part
    inv_count+= mergeSort(arr, mid+1, e);

    inv_count+= merge(arr,temp,s,mid+1,e);
    }
    return inv_count;
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
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

 return 0;
}