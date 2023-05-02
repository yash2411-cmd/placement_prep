#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int res=1;
	while(n>0){
		if(n&1){
			// for odd case we know we only need to multiple x with result one time
			res= (1LL*(res) * (x)%m)%m;
		}
		// and in rest case 
		x= (1LL*(x)%m * (x)%m)%m;
		n= n>>1; // using right shift to divide n by 2
	}
	return res;
}

int main(){
    int n, m, x;
    cin>>n>>m>>x;
    cout<<modularExponentiation(x,n,m)<<endl;
    return 0;
}