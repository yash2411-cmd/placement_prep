#include<bits/stdc++.h>
using namespace std;
void print(int *p){
    cout<<*p<<endl;
}

void update(int *p){
    p=p+1;
    cout<<"inside update: "<<p<<endl;
}

int main()
{
    int n=5;
    int *p= &n;
    print(p);
    cout<<"before update: "<<p<<endl;
    update(p);
    cout<<"after update: "<<p<<endl;
 return 0;
}