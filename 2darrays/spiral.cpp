#include<bits/stdc++.h>
using namespace std;

 vector<int> spiralOrder(vector<vector<int>>& matrix) {

            vector<int>ans;
            int r=matrix.size();
            int c=matrix[0].size();

            // vector<int>ans;
            int srow= 0;
            int erow= r-1;
            int scol= 0;
            int ecol=c-1;
            int count=0;
            int total= r*c;
            while(count<total){

                for(int i=scol;count<total && i<=ecol;i++){
                    count++;
                    ans.push_back(matrix[srow][i]);
                }srow++;
                for(int i=srow;count<total && i<=erow;i++){
                    count++;
                    ans.push_back(matrix[i][ecol]);
                }ecol--;
                for(int i=ecol;count<total && i>=scol;i--){
                    count++;
                    ans.push_back(matrix[erow][i]);
                }erow--;
                for(int i=erow;count<total && i>=srow;i--){
                    count++;
                    ans.push_back(matrix[i][scol]);
                }scol++;


            }
            return ans;
    }