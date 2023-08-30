#include<bits/stdc++.h>
using namespace std;

class kqueues{

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;

    public:
    // constructor
        kqueues(int n,int k){
            this-> n = n;
            this-> k = k;
            front = new int[k];
            rear = new int[k];
            
            // intialize front and rear with -1
            for(int i=0;i<k;i++){
                front[i]=-1;
                rear[i]=-1;
            }
            next = new int[n];
            // intialize next array
            for(int i=0;i<n;i++){
                next[i]=i+1;
            }
            next[n-1]= -1;
            arr = new int[n];
            freespot = 0;
        }

    // push function
        void enqueue(int data, int qn){
            if(freespot == -1){
                cout<<"no empty space to push"<<endl;
                return;
            }
            int index = freespot;
            freespot= next[index];

            if(front[qn-1]==-1){
                front[qn-1]= index;
            }
            else{
                // linking new to previous element
                next[rear[qn-1]]= index;
            }
                next[index] = -1;
                rear[qn-1]= index;
                arr[index]= data;
        }

        int dequeue(int qn){
            if(front[qn-1]==-1){
                cout<<"underflow"<<endl;
                return -1;
            }
            int index = front[qn-1];
            // update front
            front[qn-1]= next[index];

            // manage free spot
            next[index]= freespot;
            freespot= index;

            return arr[index];
        }

};


int main()
{

    kqueues q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
 return 0;
}