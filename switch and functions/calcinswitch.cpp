#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"enter value of a: ";
    cin>>a;
    cout<<"enter value of b: ";
    cin>>b;
    char op;
    cout<<"enter the operation you want to perform: ";
    cin>>op;

    switch (op)
    {
    case '+':
        cout<<"a+b: "<<a+b<<endl;
        break;
    case '-':
        cout<<"a-b: "<<a-b<<endl;
        break;
    case '/':
        cout<<"a/b: "<<a/b<<endl;
        break;
    case '*':
        cout<<"a*b: "<<a*b<<endl;
        break;
    case '%':
        cout<<"a%b: "<<a%b<<endl;
        break;
    }
    return 0;
}