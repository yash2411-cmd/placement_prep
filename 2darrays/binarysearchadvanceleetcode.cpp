#include<bits/stdc++.h>
using namespace std;

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();
        int rowin= 0;
        int colin= col-1;

        while(rowin<row && colin>=0){
            int ele= matrix[rowin][colin];
            if(ele==target)return true;
            else if(ele<target)rowin++;
            else{
                colin--;
            }
        }
        return false;
    }

int main()
{
 return 0;
}