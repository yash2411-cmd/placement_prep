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


 return 0;
}