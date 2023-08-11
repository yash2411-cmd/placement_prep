#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();

        // checking for the first column to be zero or not
        int col1= 1;
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                col1=0;
                // if first row or col is zero then set col1 to zero
            }

            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }

        // now iterating back according to the above points to set zeros's
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col1==0){
                matrix[i][0]=0;
            }
        }

    }
};



int main()
{
 return 0;
}