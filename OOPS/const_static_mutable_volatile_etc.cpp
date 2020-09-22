#include <iostream>
#include <cstring>
using namespace std;
//STATIC

// Persistence: it remains in memory until the end of the program.

// File scope: it can be seen only withing a file where it's defined.

// Visibility: if it is defined within a function/block, it's scope is limited to the function/block.
//It cannot be accessed outside of the function/block.

// Class: static members exist as members of the class rather than as an instance in each object of the class.
//So, this keyword is not available in a static member function. Such functions may access only static data members.
//There is only a single instance of each static data member for the entire class:

// A static data member : class variable
// A non-static data member : instance variable
// Static member function: it can only access static member data, or other static member functions
//while non-static member functions can access all data members of the class: static and non-static.

class A{
  private:
    int idx;
    string name;
    static int noOfObjects;
  public:
    A(){
      idx=100;
      name="Moksh";
      noOfObjects++;
    }
    A(int a,string s){
      idx=a;
      name=s;
      noOfObjects++;
    }
    //non static function can access static as well as non static data members
    void show(){
      cout<<endl<<"Show function called";
      cout<<endl<<"The index is "<<idx<<" and name is "<<name<<endl;
      cout<<"The No. of Objects currently are :-"<<noOfObjects;//works just fine
    }
    //can only access static data members and variables
    static void showCount(){
      cout<<endl<<"The No. of Objects are : "<<noOfObjects<<endl;
    }
    ~A(){
      cout<<endl<<"Destructor Called"<<endl;
      noOfObjects--;
      showCount();//non static members can call static as well as non static functions and data members
    }
};
//without this most of occurences of static data member would cause trouble
//cant be initialized any other way
int A::noOfObjects=0;


//CONST and MUTABLE

//Const class member functions are made for following reasons
//The object called by these functions cannot be modified.ie these functions cant change any objects value
//It is recommended to use const keyword so that accidental changes to object are avoided.

//const argument parameter is used when we need to make sure the parameter must not be changed

//const object declaration means once given values using constructors the values can't be changed
//if try to then compiler raises an error

//mutable data members can even be changed if object is declared const

//A const member function can be called by any type of object.
//Non-const functions can be called by non-const objects only.
class B{
  private:
    int i,j;
    mutable int x;
  public:
    B(){
      i=34;
      j=89;
      x=56;
    }
    B(int a,int b,int c){
      i=a;
      j=b;
      x=c;
    }
    void changeX(int m) const{
      x=m;
    }
    void changeI(int m){
      i=m;
    }
    void show(){
      cout<<endl<<"i is "<<i<<" and j is "<<j<<" and mutable x is "<<x<<endl;
    }
    void print() const{
      cout<<endl<<"i is "<<i<<" and j is "<<j<<" and mutable x is "<<x<<endl;
    }
    void changeVal() const{
      // if below uncommented then compiler error
      // i+=10;
      cout<<"Change Val called";
    }
};
//VOLATILE
// syntax :- volatile a;

// The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler.

// Objects declared as volatile are omitted from optimization because their values can be changed by code outside the scope of current code at any time.
// The system always reads the current value of a volatile object from the memory location rather than keeping its value in temporary register at the point it is requested

// maybe used in C++ code which is dealing with peripheral devices, IO ports (mainly memory mapped IO ports), Interrupt Service Routines (ISRs) which interact with Hardware.
int main(){
  //STATIC
  //below line gives error as noOfObjects is a private member
  //cout<<A::noOfObjects;
  A a1,a2(2,"Gautam");
  a1.show();
  a2.show();
  A *ptr=new A(3,"Gopal");
  ptr->show();
  A::showCount();//output = 3
  delete ptr;
  A::showCount();//output = 2

  //CONST and MUTABLE
  B b1;
  b1.changeVal();
  b1.show();
  b1.changeX(127);
  b1.changeI(298);
  b1.show();
  const B b2(256,512,2048);
  // b2.show();//ERROR  as const object cant call non const functions
  b2.print();
  b2.changeX(1024); //succesful
  b2.print();
  b2.changeI(1);


  return 1;
}
