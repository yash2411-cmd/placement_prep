#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int si= q.size();
        while(si>1){
            q.push(q.front());
            q.pop();
            si--;
        }
    }
    
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

// using deque tc and sc is O(1);
/*
class MyStack {
public:
    deque<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push_front(x);
    }
    
    int pop() {
        if(!q.empty()){
            int ele = q.front();
            q.pop_front();
            return ele;
        }
        else{
            return -1;
        }
    }
    
    int top() {
        if(!q.empty()){
            return q.front();
        }
        else{
            return -1;
        }
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
*/

int main()
{
 return 0;
}