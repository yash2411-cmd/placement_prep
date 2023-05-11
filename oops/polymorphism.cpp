#include<bits/stdc++.h>
using namespace std;

// compile time polymorphism
class a{
    // function overloading
    public:
    void sayhello(){
        cout<<"Hello yash"<<endl;
    }
    void sayhello(string name){
        cout<<"hello "<<name<<endl;
    }
    int sayhello(int age){
        return age;
    }
};

// operator overloading
class B{
    public:
    int a;
    int b;
    public:
    void operator+ (B &obj){
        int val1= this->a;
        int val2= obj.a;
        cout<<"output is: "<<val2-val1<<endl;
    }
};

// runtime polymorphism
// method overriding, inheritance is important and functions should have same name and same arguments and parameters
class animal{
    public:
    void speak(){
        cout<<"speaking.."<<endl;
    }
};
class dog: public animal{
    public:
    void speak(){
        cout<<"barking..."<<endl;
    }
};

int main()
{
    a obj;
    obj.sayhello();
    obj.sayhello("yash");
    cout<<obj.sayhello(21)<<endl;

    B o1,o2;
    o1.a=10;
    o2.a= 13;
    o1+o2;

    dog d;
    d.animal::speak();

 return 0;
}