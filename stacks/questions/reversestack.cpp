#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    solve(stack,num);
}