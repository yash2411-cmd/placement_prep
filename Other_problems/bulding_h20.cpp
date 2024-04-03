#include <bits/stdc++.h>
using namespace std;

// this problem is a problem based on operating system concept called concurrency

class H2O
{
    mutex m;
    condition_variable c;
    int flag;

public:
    H2O()
    {
        flag = 0;
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        unique_lock<mutex> lock(m);
        while (flag > 1)
        {
            c.wait(lock);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        c.notify_all();
        flag++;
    }

    void oxygen(function<void()> releaseOxygen)
    {
        unique_lock<mutex> lock(m);
        while (flag <= 1)
        {
            c.wait(lock);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        c.notify_all();
        flag = 0;
    }
};

int main()
{
    return 0;
}