#include<bits/stdc++.h>
using namespace std;

// leetcode

// Q: Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]


    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n, 0));
        int srow=0;
        int erow=n-1;
        int scol=0;
        int ecol=n-1;
        int count=0;

        int total=n*n;
        while(count<total){
            for(int i=scol;count<total && i<=ecol;i++){
                    count++;
                    ans[srow][i]=count;
                }srow++;
                for(int i=srow;count<total && i<=erow;i++){
                    count++;
                    ans[i][ecol]=count;
                }ecol--;
                for(int i=ecol;count<total && i>=scol;i--){
                    count++;
                    ans[erow][i]=count;
                }erow--;
                for(int i=erow;count<total && i>=srow;i--){
                    count++;
                    ans[i][scol]=count;
                }scol++;

        }
        return ans;

    }

int main()
{
 return 0;
}