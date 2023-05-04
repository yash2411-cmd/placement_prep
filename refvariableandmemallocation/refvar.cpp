#include<bits/stdc++.h>
using namespace std;

void update(int n){
    n++;
}
void update2(int &n){
    n++;
}

int main()
{
    int i=5;
    // create a reference variable
    int &j= i; 

    j++;
    // cout<<j<<endl;

    int n=8;
    // cout<<"before: "<<n<<endl;
    // update(n);
    // cout<<"after: "<<n<<endl;

    cout<<"before: "<<n<<endl;
    update2(n);
    cout<<"after: "<<n<<endl;

 return 0;
}