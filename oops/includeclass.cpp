#include<bits/stdc++.h>
// #include "class.cpp"
using namespace std;

class vilian{
public:

    // properties of class vilian 
    char Name;
    int age;

    // getter
    char get_Name(){
        return Name;
    }
    int get_age(){
        return age;
    }

    // setters, setter me condition bhi laga sakte ho
    char set_Name(char ch){
        Name= ch;
    }
    // int set_age(int x, char name){
    int set_age(int x){
        // if(name=='a'){
        //     age= x;
        // }
        age= x;
    }
};

int main()
{
    // static allocation 
    vilian v1;
    // v1.Name = 'yash';
    // v1.age = 21;

    cout<<"size of v1: "<<sizeof(v1)<<endl;
    // v1.set_age(21,'a');
    v1.set_age(21);
    v1.set_Name('Y');

    cout<<v1.get_age()<<endl;
    cout<<v1.get_Name()<<endl;

    // dynamic allocation
    vilian *v2= new vilian; 
    cout<<"size of v2: "<<sizeof(v2)<<endl;

    // derefrencing
    (*v2).set_age(19);
    (*v2).set_Name('S');

    cout<<"age of v2: "<<v2->get_age()<<endl;
    cout<<"age of v2: "<<v2->get_Name()<<endl;


 return 0;
}