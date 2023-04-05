//  we have a total amount of 1330, print how many notes of 100, 50, 20, 1 are required to make the amount possible??

#include<iostream>
using namespace std;

int main(){
    int n=1276;
    int hun=0;
    int fif= 0;
    int twen= 0;
    int one= 0;
        hun = n/100;
        n=n-(100*hun);
        fif= n/50;
        n= n-(50*fif);
        twen= n/20;
        n= n-(20*twen);
        one = n;
        cout<<hun<<" Notes of hundred + "<<fif<<" Notes of fifty + "<<twen<<" Notes of twenty + "<<one<<" Notes of one."<<endl;

}