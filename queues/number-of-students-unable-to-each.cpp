#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count =0;
        int i=0;
        queue<int>q;

        for(auto j:students){
            q.push(j);
        }

        while(count< q.size() && i< sandwiches.size()){
            if(sandwiches[i]==q.front()){
                q.pop();
                i++;
                count=0;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};


int main()
{
 return 0;
}