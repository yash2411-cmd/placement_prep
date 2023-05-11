#include<bits/stdc++.h>
using namespace std;


// hierarical iniheritance
class human{
    public:
    int age;
    int height;
    void speak(){
        cout<<"hey"<<endl;
    }
};

class boy:public human{

};
class girl: public human{

};



int main()
{
    boy b;
    girl g;
    cout<<b.age<<endl;
    cout<<g.age<<endl;

 return 0;
}