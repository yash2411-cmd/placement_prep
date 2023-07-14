#include<bits/stdc++.h>
class SpecialStack {
    public:
    stack<int>s;
    int mini = INT_MAX;        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data<mini){
                s.push(2*data-mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

      int pop() {
        
        if(s.empty())
         return -1;
        int curr=s.top();
        s.pop();
        if(curr > mini)
        {
            return curr;
        
        }
        else
        {
            int prevMini=mini;
            int val=2*mini-curr;
            mini=val;
            return prevMini;
        }
        
    }

    int top() {
        // Implement the top() function.
         if(s.empty()){
            return -1;
        }
        int curr= s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }
        return mini;

    }  
};