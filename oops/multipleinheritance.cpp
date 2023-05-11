#include<bits/stdc++.h>
using namespace std;

class human{
    public:
    void speak(){
        cout<<"hey"<<endl;
    }
};

class animal{
    public:
    void bark(){
        cout<<"barking"<<endl;
    }
};

class multi: public human, public animal{

};

int main()
{
    multi m;
    m.bark();
    m.speak();
 return 0;
}