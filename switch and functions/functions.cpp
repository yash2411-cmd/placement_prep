#include<bits/stdc++.h>
using namespace std;



// even odd function
void evenodd(int n){
    if(n%2==0){
        cout<<"Integer is even"<<endl;
    }
    else{
        cout<<"Integer is odd"<<endl;

    }
    return;
}


// pow function
int pow(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
    return ans;
}

// prime not prime
void isprime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<"Number is Not Prime"<<endl;
            return;
        }
    }
    cout<<"Number is Prime"<<endl;
    return;
}
// 1 to n list print
void listprint(int n){
    cout<<"counting from 1 to "<<n<<" is: ";
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}
// sum of n natural numbers
void sumnatural(int n){
    cout<<"sum of natural numbers is: ";
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<sum<<endl;
}
// sum of first n odd numbers and even numbers
// factorial
int fact(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans= ans*i;
    }
    return ans;
}
// calculate nCr = n!/(r!*(n-r)!)
int ncr(int n, int r){
    int num= fact(n);
    int denom= fact(r)*fact(n-r);

    return num/denom;
}


int main(){
    int n; cin>>n;
    evenodd(n);
    isprime(n);
    sumnatural(n);
    listprint(n);
    cout<<"factorial of "<<n<<" is: "<<fact(n)<<endl;
    cout<<"enter value of r to calculate nCr: ";
    int r;cin>>r;
    cout<<"nCr is: "<<ncr(n,r)<<endl;
    cout<<"enter the value of a and b to calculate a to the power of b: ";
    int a,b; cin>>a>>b;
    cout<<"a to the power of b is :"<<pow(a,b)<<endl;
    return 0;
}
