#include <iostream>
#include <cstring>
using namespace std;
class GrandParent{
  private:
    int a,b,c;
    string *s;
  public:
    GrandParent(){
      this->a=100;
      this->b=200;
      this->c=300;
      s=new string("default constructor");
    }
    //never do this.a always this->a as this represent a pointer which holds address of calling object
    GrandParent(int a,int b,int c){
      this->a=a;
      this->b=b;
      this->c=c;
      s=new string("Parameterized Constructor");
    }
    //while runing code comment out at least one copy constructor
    // Shallow Copy Constructor
    GrandParent(const GrandParent& temp){
      //shallow copy constructor is called
      cout<<endl<<"Shallow Copy function called"<<endl;
      this->a=temp.a;
      this->b=temp.b;
      this->c=temp.c;
      this->s=temp.s;
      //points to the same variable s of temp eventhough it is dynamic variable
    }

    //Deep Copy Constructor
    GrandParent(const GrandParent& temp){
      cout<<endl<<"Deep Copy function called"<<endl;
        this->a=temp.a;
        this->b=temp.b;
        this->c=temp.c;
        string temp_s=*(temp.s);
        this->s=new string(temp_s);
        //points to the new dynamic variable for s doesnt matter for static variables
    }
    void setString(string a){
      delete s;
      s=new string(a);
      show();
    }
    void show(){
      cout<<endl<<" A : "<<this->a<<"\n B : "<<this->b<<"\n C : "<<this->c<<"\n String is : "<<*s<<"\n String address : "<<s<<endl;
    }
    //overloaded function must only have one argument if binary operation like + has to be there
    //if unary operator like negate whatever is there is present than no argumenet and just use this-> operator
    //unary operator overloading
    void operator++(){
      //all this unary overloaded operator does is makes the string all caps
      cout<<endl<<"This '++' function was called "<<endl;
      string a=*(this->s);
      for(auto itr=a.begin();itr<a.end();itr++){
        *itr=toupper(*itr);
      }
      cout<<a;
      this->s=new string(a);
      show();
    }
    //binary operator overloading
    GrandParent operator+(GrandParent temp1){
      cout<<"This '+' function was called "<<endl;
      GrandParent newG;
      newG.a=this->a+temp1.a;
      newG.b=this->b+temp1.b;
      newG.c=this->c+temp1.c;
      string tempNewString=*(this->s) +(string)" ==&&== " + *(temp1.s);
      newG.s=new string(tempNewString);
      return newG;
    }
    //below is the list of operator that can be overloaded
    //some may be already fixed as unary or binary
    //+    -    *    /      %        ^ &    |    ~    !,  =    ++ --  ==    !=      &&  ||  +=    -=    /=    %=      ^=        &= |=    *=    =      []        () ->    ->*    new    new []      delete    delete []

    //below is the list of operator that can't be overloaded ever
    // 1> Scope Resolution Operator  (::)
    // 2> Pointer-to-member Operator (.*)
    // 3> Member Access or Dot operator  (.)
    // 4> Ternary or Conditional Operator (?:)
    // 5> Object size Operator   (sizeof)
    // 6> Object type Operator   (typeid)
    ~GrandParent(){
      cout<<endl<<"Destuctor Called"<<endl;
    }

};
int main(){
  GrandParent gprt1;
  GrandParent gprt2(1,8,64);
  string a;
  gprt1.show();
  gprt2.show();
  cout<<"Enter New String For GPR1 : ";
  getline(cin,a);
  gprt1.setString(a);
  GrandParent gprt3=gprt1+gprt2;
  gprt3.show();
  GrandParent gprt4=gprt1+gprt3;
  gprt4.show();
  ++gprt4;//capitalises using "int toupper(int ch)" the string
  GrandParent gprt5(gprt1);
  gprt5.show();
  return 1;
}
