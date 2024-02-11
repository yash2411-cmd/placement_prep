#include <bits/stdc++.h>
using namespace std;

class heap
{

public:
    int arr[1000];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val) // time complexity is O(logn)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1 && arr[index] > arr[index / 2])
        {
            swap(arr[index], arr[index / 2]);
        }
    }

    void deletefromheap() // time complexity is O(logn)
    {
        if (size == 0)
        {
            cout << "Nothing To Delete!" << endl;
            return;
        }

        // put the last element at root
        arr[1] = arr[size];
        size--;

        // put the root at its correct position
        int i = 1;
        while (i < size)
        {
            // find the leftindex  and rightindex of current node
            int left = 2 * i;
            int right = 2 * i + 1;
            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] > arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // for one based indexing we need to add <= for compairing the left and n and same for right
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    // deleting the root
    h.deletefromheap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // by deafualt it is max heap;
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    cout << "Top element of max heap is: " << pq.top() << endl;

    // creating a min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(345);
    minheap.push(34);
    minheap.push(35);
    minheap.push(45);
    minheap.push(3);
    cout << "After making it a min heap, top element is :" << minheap.top() << endl;
    return 0;
}