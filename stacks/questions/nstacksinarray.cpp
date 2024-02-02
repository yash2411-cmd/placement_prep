#include <bits/stdc++.h>
class NStack
{
    int *arr;
    int *top;  // array for keeping track of top
    int *next; // array for storing free slots indeces

    int n;        // number of stacks
    int s;        // size of array
    int freespot; // pointing to next freeslot

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // intialise top array with -1
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // intialize next array
        for (int j = 0; j < s; j++)
        {
            next[j] = j + 1;
        }
        // last points to empty space outside the array so -1
        next[s - 1] = -1;
        // initially freespot is zero
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1)
            return false;
        // find the index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // push x in stack
        arr[index] = x;

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;
        return true;

        // Write your code here.
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
        // Write your code here.
    }
};