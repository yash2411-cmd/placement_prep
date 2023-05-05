#include<bits/stdc++.h>
using namespace std;

void saydigit(int n, string arr[]){
    if(n==0)return;
    int dig= n%10;
    n/=10;
    saydigit(n,arr);
    cout<<arr[dig]<<" ";
}

int main()
{
    string arr[10]= {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;
    cout<<endl;
    saydigit(n,arr);
 return 0;
}