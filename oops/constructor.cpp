#include<bits/stdc++.h>
// #include "class.cpp"
using namespace std;

class vilian{
public:

    // properties of class vilian 
    char *Name;
    int age;

    // user defined constructor without parameters
    vilian (){      // jese hi hum constructor likh dete hain to deafult vala khtm ho jata hai
        cout<<"contructor called."<<endl;
        // name = new char[100];
    }

    // user defined constructor with parameters
    vilian (int age){
        this->age = age;
        // this->Name= Name;
    }

    // copy constructor & we need to pass it by refrence
    // vilian (vilian &v){
    //     // deep copy 
    //     char *ch = new char[strlen(v.name)+1];
    //     strcpy(ch, v.name);
      
    //     // shallow copy
    //     this->Name= ch;
    //     cout<<"Copy constructor call hua hai."<<endl;
    //     this->age= v.age;
    //     // this->Name= v.Name;
    // }

    print (){
        cout<<"Name : "<<Name<<endl;
        cout<<"Age : "<<age<<endl;
    }
    setname (char name[]){
        strcpy(this->Name,name);
    }

    ~vilian(){
        cout<<"destructor called! "<<endl;
    }

    // static keyword which belongs to class , no need to make an object for it
    static int time; 

    // static function -> also belongs to class and can only access static keywords, no need to create an object
    static int random(){
        return time;
    }

};

int vilian::time= 54;

int main(){
    // right way to access 
    cout<<vilian::time<<endl;
    cout<<vilian::random()<<endl;
    // static -> isme automatically destructor call ho jata hai
    vilian yash;


    // dynamic allocated -> isme manually destrcutor ko call krna pdega
    vilian *aman = new vilian();
    delete aman;

    















    // // statically object creation
    // vilian yash(21,'u');    
    // // yash.Name = 'y';
    // // yash.age= 
    // // cout<<yash.age<<endl;
    // yash.print();


    // // dynamically creation of object
    // vilian *v2= new vilian(19,'Y');
    // v2->print();
    // // cout<<v2->Name<<endl;

    // cout<<"Copy Constructor implement hua hai niche: "<<endl;
    // vilian aman(21,'I');

    // // mene bola naya object banao aur usme aman ko copy krdo
    // vilian sid(aman);
    // sid.print();


    // vilian r(21);
    // // r.age(21);
    // char name[5]= "yash";
    // r.setname(name);
    // r.print();

    // vilian v(r);

    // r.Name[0]= 'D';
    // r.print();

    // v.print();



    


}