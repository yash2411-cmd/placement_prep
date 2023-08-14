#include<bits/stdc++.h>
using namespace std;
int main()
{

    deque<int>d;
    d.push_front(12);
    d.push_back(24);
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
 return 0;
}

// implementation of deque

class Deque
{
public:
    // Initialize your data structure.
    int size;
    int *arr;
    int front;
    int rear;
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr= new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull()){
            // cout<<"Queue is full"<<endl;
            return false;
        }
        else if(front ==-1){
            front = rear = 0;
        }
        else if(front ==0 && rear!=size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front]= x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()){
            // cout<<"Queue is full"<<endl;
            return false;
        }
        else if(front ==-1){
            front = 0;
            rear = 0;
            // arr[rear]= value;
        }
        else if(rear == size-1 && front!=0){
            rear = 0;
            // arr[rear]= value;
        }
        else{
            rear++;
        }
        arr[rear]=x;
        return true; 
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()){
            // cout<<"queue is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front]= -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front =0;
        }
        else{
            front++;
        }
        return ans;

    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()){
            // cout<<"queue is empty"<<endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear]= -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear= size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
        // Write your code here.

    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1){
            // cout<<"queue is empty"<<endl;
            return true;
        }
        else{

        return false;
        }

    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || ( front != 0 && rear == (front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }

    }
};