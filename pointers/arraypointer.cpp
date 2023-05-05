#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10]= {1,2,3,4,5,6,7,8,9,99};

    // printing address of locations
    cout<<arr<<endl;
    cout<<&arr[1]<<endl;

    // printing values at location
    cout<<"value at 1st index: "<<*(arr)+1<<endl;

    // different way of accessing elements
    int i=6;
    cout<<i[arr]<<endl;

    int *ptr= &arr[5];
    cout<<"size of array: "<<sizeof(arr)<<endl;
    cout<<"size of ptr: "<<*ptr<<endl;
    cout<<"size of ptr: "<<sizeof(&ptr)<<endl;


    


 return 0;
}