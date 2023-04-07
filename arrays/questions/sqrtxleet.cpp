#include<bits/stdc++.h>
using namespace std;

double prec(int n, int prec, int tempsol){
	double factor=1;
	double ans=tempsol;
	for(int i=0;i<=prec;i++){
		factor=factor/10;
		for(double j=ans;j*j<n;j+=factor){
			ans=j;
		}
	}
	return ans;
}

int mySqrt(int n) {
        // implemented binary search
        int i=0, j=n, ans;
		while(i<=j){
			long long int mid=i+(j-i)/2;
			if(mid*mid==n){ans = mid; break;}
			else if(mid*mid<n){i=mid+1;}
			else{j=mid-1;}
		}
		return ans;
    }

int main(){
    int n;cin>>n;
	int temp= mySqrt(n);

    cout<<prec(n,3,temp);
    return 0;
}