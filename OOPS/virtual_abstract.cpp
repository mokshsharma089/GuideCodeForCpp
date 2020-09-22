#include <iostream>
#include <cstring>
using namespace std;
//VIRTUAL keyword
// A virtual function is a member function which is declared within a base class and is re-defined(Overriden) by a derived class
// When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function.
// Used to achieve Runtime polymorphism


// Rules for Virtual Functions
// 1.Virtual functions cannot be static and also cannot be a friend function of another class.
// 2.Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
// 3.The prototype of virtual functions should be same in base as well as derived class.
// 4.They are always defined in base class and overridden in derived class. It is not mandatory for derived class to override (or re-define the virtual function), in that case base class version of function is used.
// 5.A class may have virtual destructor but it cannot have a virtual constructor.

// Late binding(Runtime) is done in accordance with the content of pointer (i.e. location pointed to by pointer) and
// Early binding(Compile time) is done according to the type of pointer,

class A{
  public:
    virtual void show(){
      cout<<endl<<"Show Function called inside A"<<endl;
    }
    void print(){
      cout<<endl<<"Print function called inside A"<<endl;
    }
};
class B : public A{
  public:
    void show(){
      cout<<endl<<"Show Function called inside B"<<endl;
    }
    void print(){
      cout<<endl<<"Print function called inside B"<<endl;
    }
};

//PURE Virtual functions and abstract classes

// A pure virtual function is a member function of base class whose only declaration is provided in base class and should be defined in derived class otherwise derived class also becomes abstract.
//Any class containing pure virtual function becomes abstract. i.e. it cannot be instantiated.(compiler would give error if we try to make an object of abstract class)
// If derived class do not redefine virtual function of base class, then no compilation error but derived class also becomes abstract just like the base class

class C{
  protected:
    string name;
  public:
    C(){
      name="Bholu Bhai";
    }
    virtual void print()=0;//pure virtual function
    //class becomes abstract as it has a pure virtual function
    void printName(){
      cout<<endl<<"Name is "<<name;
    }
};
class D:public C{
  private:
    int age;
  public:
    D():C(){
      age=22;
    }
    void print(){
      cout<<endl<<"Inside the redefination of pure virtual Function";
      cout<<endl<<"Details are ";
      printName();
      cout<<endl<<"Age is "<<age<<endl;
    }
};
int main(){
  // //function overriding only happens when base pointer points to derived object or reference
  // //no overriding in this case
  A a1;
  B b1;
  a1.show();
  a1.print();
  b1.show();
  b1.print();
  //Output=
    // Show Function called inside A
    // Print function called inside A
    // Show Function called inside B
    // Print function called inside B

  // //function overriding will take place when pointers are used in right always
  A *aptr;
  B b1;
  aptr=&b1;
  aptr->show();//function of B is called as show is made virtual in A's defination otherwise would have showed A's show fucntion
  aptr->print();//function of A is called as this is the example of early binding where decision is made on base of pointer type rather than type pointer is pointing to
  //Output
    // Show Function called inside B
    // // Print function called inside A

  //pure virtual functions and abstract classes
  //below gives error
  C c;
  c.printName();//gives error " error: variable type 'C' is an abstract class C c;" so no objects of Class C can be made
  D d1;
  d1.print();
  //Output
    // Inside the redefination of pure virtual Function
    // Details are
    // Name is Bholu Bhai
    // Age is 22
  return 1;
}
