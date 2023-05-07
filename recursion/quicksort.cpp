#include<bits/stdc++.h>
using namespace std;


int partition(int arr[],int s, int e){

    int pivot = arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    // yaha mene right index nikal liya
    int pivotindex= s+count;
    // aur me swap krdunga element ko pivotindex ke element se
    swap(arr[s],arr[pivotindex]);

    // now handling the left and right part condition so that the element right part should be greater and left part should be smaller
    int i=s;
    int j=e;
    while (i<pivotindex && j>pivotindex)
    {
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    
    return pivotindex;


}



void quicksort(int arr[],int s, int e){

    // base case 
    if(s>=e){
        return;
    }

    // doing partition to place the element in its right position and getting pivot element index
    int p= partition(arr,s,e);

    // left part ko sort karenge
    quicksort(arr,s,p-1);

    // right part ko sort karenge
    quicksort(arr,p+1,e);
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
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


 return 0;
}