#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // step 1 push all elements in stack
        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        // step 2 jabtak size is not equal to 1 pop 2 elements
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        // step 3 single element in stack now we check of that candidate is a celebrity or not
        int candidate= s.top();
        int zerocount=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0){
                zerocount++;
            }
        }
        if(zerocount!=n)return -1;
        
        int onecount= 0;
        for(int i=0;i<n;i++){
            if(M[i][candidate]==1){
                onecount++;
            }
        }
        
        if(onecount!=n-1)return -1;
        
        return candidate;
    }
};


int main()
{
 return 0;
}