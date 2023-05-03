#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    cout<<n<<endl;
    // address of operator -> &
    cout<<"address of n is: "<<&n<<endl;

    // declaration of pointer
    int *ptr= &n;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    
    // size of pointer is: size0f()
    cout<<"size of pointer is: "<<sizeof(ptr)<<endl;
    cout<<"size of integer is: "<<sizeof(n);

    // increment and decrement with pointer
    int *p= &n;
    cout<<"value of n before increment: "<<n<<endl;
    (*p)++;
    cout<<"value of n after increment: "<<n<<endl;
    
    // important 
    int i=9;
    int *t= &i;
    cout<<"before increment: "<<t<<endl;
    t= t+1;
    cout<<"after increment: "<<t<<endl;
 
    return 0;
}