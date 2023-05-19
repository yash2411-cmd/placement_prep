#include<bits/stdc++.h>
using namespace std;

class Stack{
    // properties
    public:
    int *arr;
    int top;
    int size;



    // functions
    Stack(int size){
        this-> size= size;
        arr= new int[size];
        top = -1;
    }

    void push(int element){
        if(size-top > 1){
            top++;
            arr[top]= element;
        }
        else{
            cout<<"StackOverflow"<<endl;
        }
    }

    void pop(){
        if(top > -1){
            top--;
        }
        else{
            cout<<"StackUnderflow"<<endl;
        }
    }

    int peek(){
        if(top > -1){
            return arr[top];
        }
        else{
            cout<<"StackUnderflow"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if(top == -1){
            return true;
        }
        return false;
    }



};




int main()
{
    Stack st(5);
    st.push(22);
    st.push(42);
    st.push(78);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    
    if(st.isempty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

 return 0;
}