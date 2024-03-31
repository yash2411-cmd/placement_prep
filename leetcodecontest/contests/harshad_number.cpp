#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sum(int n){
        int sum =0;
        while(n>0){
            int dig  = n%10;
            sum += dig;
            n/=10;
        }
        return sum;
    }
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = sum(x);
        if(x%s==0){
            return s;
        }
        else{
            return -1;
        }
    }
};

int main()
{
 return 0;
}