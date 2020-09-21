#include <iostream>
using namespace std;

//function templates
template<typename T>
void print(T a){
  cout<<endl<<"sizeof datatype : "<<sizeof(T)<<endl;
  cout<<endl<<"Value of variable is "<<a<<endl;
}

//class templates
template<typename T=char,int size=3>
class A{
  private:
    T array[size];
    int used;
  public:
    A(){
      used=-1;
    }
    void push(T a){
      if(used>=size){
        cout<<endl<<"Can't Push "<<a<<" into array , Array full"<<endl;
      }
      else{
        used++;
        array[used]=a;
      }
    }
    void pop(){
      if(used<=0){
        cout<<endl<<"Array is Empty,push something first"<<endl;
      }
      else{
        used--;
      }
    }
    void show();
};
template<typename T,int size>
void A<T,size>::show(){
  cout<<endl<<"Inside Show function "<<endl;
  for(int i=0;i<=used;i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}
int main(){
  print<int>(5);
  print<char>('a');

  A<int,5> vec;
  vec.show();
  vec.pop();
  vec.push(3);
  vec.push(97);
  vec.push(56);
  vec.show();
  vec.pop();
  vec.show();

  A<char> vec1;
  vec1.show();
  vec1.pop();
  vec1.push('A');
  vec1.push('B');
  vec1.push('R');
  vec1.push('q');
  vec1.pop();
  vec1.push('a');
  vec1.push('m');
  vec1.push('j');
  vec1.show();

  A vec2;//shows error
  A<> vec2;//works fine with type = char
  vec2.show();
  vec2.pop();
  vec2.push('A');
  vec2.push('B');
  vec2.show();

  return 1;
}
