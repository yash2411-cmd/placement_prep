#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>s;
    // push operation for inserting elements in stack
    s.push(1);
    s.push(2);
    s.push(3);
    // sabse upar vala element delete ho jayega
    s.pop();

    cout<<"Top element in the stack is: "<<s.top()<<endl;
    if(s.empty()){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        cout<<"Stack is not empty!"<<endl;
    }
    cout<<"size of stack is: "<<s.size()<<endl;

 return 0;
}