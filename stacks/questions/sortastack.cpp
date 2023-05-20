#include <bits/stdc++.h> 

void sortedinsert(int x, stack<int> &stack){
	if(stack.empty() || (!stack.empty() && stack.top()<x)){
		stack.push(x);
		return;
	}
	int num= stack.top();
	stack.pop();
	sortedinsert(x,stack);
	stack.push(num);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	sortedinsert(num, stack);	
}