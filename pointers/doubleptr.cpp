#include<bits/stdc++.h>
using namespace std;
void update(int **p2){
    // p=p+1; // kuch change nahi hoga

    // *p2= *p2+1; // yaha change hogi value p ki

    **p2= **p2+1; // yaha change hogi value t ki
}

int main()
{
    int t= 5;
    int *p= &t;
    int ** ptr= &p; // double pointer

    cout<<"printing p: "<<p<<endl;
    cout<<"address of p: "<<&p<<endl;

    // adress of p and value of ptr will be same
    cout<<"printing value of ptr: "<<*ptr<<endl;

    //ways to access value of t from multiple pointers
    cout<<"value of t: "<<t<<endl;
    cout<<"value of t: "<<*p<<endl;
    cout<<"value of t: "<<**ptr<<endl;

    // printing value of p
    cout<<"value of p: "<<p<<endl;
    cout<<"value of p: "<<&t<<endl;
    cout<<"value of p: "<<*ptr<<endl;

    // before update 
    cout<<"before i: "<<t<<endl;
    cout<<"before p: "<<p<<endl;
    cout<<"before ptr: "<<ptr<<endl;
    
    update(ptr);
    // after update 

    cout<<"before i: "<<t<<endl;
    cout<<"before p: "<<p<<endl;
    cout<<"before ptr: "<<ptr<<endl;
    

 return 0;
}