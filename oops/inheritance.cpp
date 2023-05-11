#include<bits/stdc++.h>
using namespace std;

// parent class
class Human{
    public:
    // int age;
    int height;
    int weight;

// not accessible by male class
    private:
    int age;

    public:
    int getage(){
        return this->age;
    }
    void setweight(int w){
        this->weight= w;
    }
};


// child class
class male: public Human{

    public:
    string color;

    void sleep(){
        cout<<"me so raha hu"<<endl;
    }
};

// single inheritance
class animal{
    public:
    string gender;
    int age;

    void speak(){
        cout<<"speaking"<<endl;
    }

};
class dog: public animal{
    void bark(){
        cout<<"barking->"<<endl;
    }
};

// multi level inheritance
class labra: public dog{


};








int main()
{
    male object1;
    object1.setweight(25);
    cout<<object1.age<<endl;
    cout<<object1.weight<<endl;
    object1.sleep();
    
    // single inheritance
    dog d;
    d.speak();

    // multi level
    labra l;
    l.speak();


 return 0;
}