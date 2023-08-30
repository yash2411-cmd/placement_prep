#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int>ans;
        queue<int>qq;
        int n= q.size();
        
        for(int i=0;i<n/2;i++){
            int val= q.front();
            q.pop();
            qq.push(val);
        }
        
        while(!qq.empty()){
            int val= qq.front();
            qq.pop();
            ans.push_back(val);
            val = q.front();
            q.pop();
            ans.push_back(val);
        }
        return ans;
    }
};

int main()
{
 return 0;
}