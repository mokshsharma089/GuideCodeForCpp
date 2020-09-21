#include <iostream>
using namespace std;

// Following are some important points about friend functions and classes:
// 1) Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming.
// 2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
// 3) Friendship is not inherited
// 4) The concept of friends is not there in Java.


//friend Function
//Friend Function Like friend class, a friend function can be given special grant to access private and protected members. A friend function can be:
// a) A method of another class
// b) A global function

//this is required because compiler needs to know there will be a class of name B which would be used in a friend function in class A
class B;

class A{
  private:
    int number1,number2;
    //doesnt matter at all where we declare the function as friend ,can do it in private , public or protected class area
    //friend function that can access private , protected and public members of this class A
    friend void SumOfPrivateVariableOfClassA(A);
  public:
    A(){
      number1=10;
      number2=20;
    }
    A(int a,int b){
      number1=a;
      number2=b;
    }
    void show(){
      cout<<endl<<"A's show";
      cout<<endl<<"First Variable is "<<number1<<" and second variable is "<<number2<<endl;
    }
    friend int ReturnSumOf_ProductsOfRespectiveVariablesOfTwoObjects(A,A);
    friend void SumOFVariablesOf2Classes(A,B);
};

void SumOfPrivateVariableOfClassA(A temp){
  temp.show();
  cout<<endl<<"The Sum of Both private integers of Class are "<<temp.number1+temp.number2<<endl;
}
int ReturnSumOf_ProductsOfRespectiveVariablesOfTwoObjects(A t1,A t2){
  return t1.number1*t2.number1 + t1.number2*t2.number2;
}

class B{
  private:
    int number3,number4;
  public:
    B(){
      number3=10;
      number4=20;
    }
    B(int a,int b){
      number3=a;
      number4=b;
    }
    void show(){
      cout<<endl<<"B 's Show ";
      cout<<endl<<"First Variable is "<<number3<<" and second variable is "<<number4<<endl;
    }
    friend void SumOFVariablesOf2Classes(A,B);
};
//A function that is friend of Two Classes
void SumOFVariablesOf2Classes(A a,B b){
  a.show();
  b.show();
  cout<<endl<<"The Sum of Both private integers of Class are "<<a.number1+a.number2+b.number3+b.number4<<endl;
}


//Friend Classes
//A friend class can access private and protected members of other class in which it is declared as friend

//forward declaration
class Y;
//might also work without it depends on compiler

class X{
  private:
    int num1,num2;
    friend class Y;
    //Here class Y is a friend of Class X so Class Y has access to all members of class X ,vice versa is not true
  public:
    X(){
      num1=100;
      num2=200;
    }
    X(int a,int b){
      num1=a;
      num2=b;
    }
    void show(){
      cout<<endl<<"X 's Show ";
      cout<<endl<<"First Variable is "<<num1<<" and second variable is "<<num2<<endl;
    }
};

class Y{
  private:
    int num3,num4;
  public:
    Y(){
      num3=60;
      num4=90;
    }
    Y(int a,int b){
      num3=a;
      num4=b;
    }
    int show_and_Change_X_from_Y(X x){
      cout<<endl<<"before Change";
      x.show();
      x.num1+=2000;
      x.num2+=3000;
      cout<<endl<<"before Change";
      x.show();
    }
    void show(){
      cout<<endl<<"Y 's Show ";
      cout<<endl<<"First Variable is "<<num3<<" and second variable is "<<num4<<endl;
    }
};

int main(){
  A a1(3,5);
  A a2;
  SumOfPrivateVariableOfClassA(a1);
  cout<<endl<<ReturnSumOf_ProductsOfRespectiveVariablesOfTwoObjects(a1,a2)<<endl;
  B b1(7,8);
  SumOFVariablesOf2Classes(a1,b1);
  X x1;
  Y y1;
  x1.show();
  y1.show();
  y1.show_and_Change_X_from_Y(x1);
  return 1;
}
