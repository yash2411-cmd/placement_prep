#include<bits/stdc++.h>
using namespace std;





vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int n, long long int K) {
        
        
        deque<int>dq;
        vector<long long>ans;
        
        // first k size window processing
        for(int i=0;i<K;i++){
            if(A[i]<0){
                dq.push_back(i);
            }
        }
        
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        // rest of the window processing
        for(int i=K;i<n;i++){
            if(!dq.empty() && i-dq.front()>=K){
                dq.pop_front();
            }
            // addition
            if(A[i]<0){
                dq.push_back(i);
            }
            if(dq.size()>0){
                ans.push_back(A[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
                                                 
int main()
{
 return 0;
}
 }