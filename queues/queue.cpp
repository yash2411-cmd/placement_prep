#include<bits/stdc++.h>
using namespace std;
int main()
{
    // basic operations of queue and simple implementation
    queue<int>q;
    q.push(1);
    q.push(2);
    cout<<"front element is: "<<q.front()<<endl;
    cout<<"Size of queue is: "<<q.size()<<endl;
    q.pop();
    q.pop();
    if(q.empty()){
        cout<<"empty hain!"<<endl;
    }
 return 0;
}