#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Given any Number print the number greater than this number but possibly next smallest number which is also a palindrome
//For Eg-
// I/P - 2 3 5 4 5       O/P - 2 3 6 3 2
// I/P - 9 9 9           O/P - 1 0 0 1
// I/P - 7 8 3 3 2 2     O/P - 7 8 3 3 8 7
// I/P - 7 1 3 3 2 2     O/P - 7 1 4 4 1 7



//Algorithm

//0)Check if number is all 9's {let given number contain 'm' number of 9's }
//then the next smallest Palindrome is of form 100..001 and {total number of digits in answer would be 'm+1'}

// bool AddFromMiddle=False

// 1)make 2 pointers I and J, and point them at middle
//   1.A)if number of digits is odd then for eg 12321
//     then make them both point to 3 ,{can also point to 2 as it wouldnt change much}
//     where n is the number of digits(not indexes)
//     i=j=mid=n/2; {for 5 middle is (int)5/2=2}
//   1.B)if number of digits is even then for eg 123321
//     then make I point at 3(index 2) and J point at 3(index 3)
//     i=mid-1=n/2-1   and    j=mid=n/2 {for eg n=6 ;i=2 and j=3}
//
//
// 2)start moving i and j in opposite direction {do I--(towards start) and J++(towards end) }
//   Repeat step 2 (move both i and j one step in their direction) till Vec[i]==Vec[j]
//   2B)stop when we encounter a condition where i>=0 and j<n {both will occur at same point} //this means input was already a Palindrome
//   2C)Or VEC[I]!=VEC[J] //this means we need to copy from here //loop out from here but vec[j]=vec[i] read more in step 5
//
//
// 3)Check if stopped because bounds were reached {because of 2B} if yes then Mark boolean Variable AddFromMiddle to True as we need to perform step 6
// turn AddFromMiddle=TRUE
//
//
// 4)check if stopped because of VEC[i]!=VEC[j] {because of 2C}
//   if yes then check if VEC[i]<VEC[j] ,then also  Mark boolean Variable AddFromMiddle to True as we need to perform step 6
//   here we are checking if the first point where vec[i] and vec[j] are not equal and if vec[i]<vec[j] then only step 5 wont be necessary and we have to do step 6 also
//   turn AddFromMiddle=TRUE
//
//
// 5)from previous i and j values (if remaining in case of 2C)
//   start pasting whatever is in vec[i] to vec[j]
//   VEC[j]=VEC[i] and keep movinf till bounds are reached {i-- and j++} till i>=0 and j<n
//
//
// 6)If AddFromMiddle == TRUE then only perform otherwise no need
// start from middle (choose if one middle or two according to number of digits)
//        //for eg 121 then add 1 to 2{at index 1 } and propogate carry outwards {no carry int this case } so ans = 131
//        //for eg 12899821 then middle would be 9 and 9 so add 1 to both carry would be 1 and 0 would be stored as 10{9+1}
//        //then propogate the carry as long as it exists .final ans = 12900921
//        //better if start propogating towards left only and just mirror right value { vec[j] } to updated left value{ vec[i] }
// and add 1 to middle digit {or digits} and propogate the carry outwards{on both side}
// or could do just towards left side and mirror the value of vec[i]{left} to vec[j]{right}
bool isAll9s(vector<int> & num){
  for(int i=0;i<num.size();i++){
      if(num[i]!=9){
        return false;
      }
  }
  return true;
}
void NextSmallestPalindrome(vector<int> & num){
  if(isAll9s(num)==true){
      num[0]=1;
      for(int i=1;i<num.size();i++){
          num[i]=0;
      }
      num.push_back(1);
      return;
  }
  bool AddFromMiddle=false;
  int n=num.size();//number of digits in the number
  int mid=n/2;
  int i,j;
  //if n is even
  if(n%2==0){
    //12345678
    // i is at 4{ie index 3} j is at 5{ie index 4}
    i=mid-1;
    j=mid;
  }
  //if n is odd
  else{
    //1234321
    // i is at 3 {ie index 2 { 7/2 - 1 } }
    // j is at 3 {ie index 4 { 7/2 + 1 } }
    i=mid-1;
    j=mid+1;
  }
  while(i>=0 and j<n){
    cout<<endl;
      if(num[i]==num[j]){
        cout<<num[i]<<" = "<<num[j]<<endl;
        i--;
        j++;
      }
      else{
        cout<<"BREAK because "<<num[i]<<" and "<<num[j]<<" dont match"<<endl;
        break;
      }
  }
  if(i<0){
    cout<<endl<<"Original Number Was a palindrome so Add From Middle"<<endl;
    AddFromMiddle=true;
  }
  else if(num[i]<num[j]){
    cout<<endl<<"Add From Middle because "<<num[i]<<" < "<<num[j]<<endl;
    AddFromMiddle=true;
  }
  while(i>=0){
    num[j]=num[i];
    i--;
    j++;
  }

  //AddFromMiddle==true only if
  // Either
  //A. original number is a Palindrome
  // Or
  //B. the index(place) where i and j stopped being equal num[i]<num[j]
  if(AddFromMiddle==true){
    int carry = 1;
    i = mid - 1;
    //if odd digits then carry = (num[mid]+1)/10 and j=mid+1;
      if(n%2 == 1){
        num[mid] += carry;
        carry = num[mid] / 10;
        num[mid] %= 10;
        j = mid + 1;
      }
      else{
        j = mid;
      }
    //start adding and mirroring till i>=0
      while (i >= 0)
      {
        num[i] += carry;
        carry = num[i] / 10;
        num[i] %= 10;
        num[j++] = num[i--]; // copy mirror to right
      }
    }
}
void print(const vector<int> & a){
  cout<<endl<<"------------Print Vector------------"<<endl;
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
int main(){
  vector<int> vec;
  //number is 99999
  // vec.push_back(9);
  // vec.push_back(9);
  // vec.push_back(9);
  // vec.push_back(9);
  // vec.push_back(9);

//Case 1, no need for AddFromMiddle

  //number is 783322{even number of digits}
  // vec.push_back(7);
  // vec.push_back(8);
  // vec.push_back(3);
  // vec.push_back(3);
  // vec.push_back(2);
  // vec.push_back(2);

  //number is 7678112{odd number of digits}
  // vec.push_back(7);
  // vec.push_back(6);
  // vec.push_back(7);
  // vec.push_back(8);
  // vec.push_back(1);
  // vec.push_back(1);
  // vec.push_back(2);

//Case 2, need for AddFromMiddle

  //number is 123321
  // vec.push_back(1);
  // vec.push_back(2);
  // vec.push_back(3);
  // vec.push_back(3);
  // vec.push_back(2);
  // vec.push_back(1);

  //number is 1239321
  // vec.push_back(1);
  // vec.push_back(2);
  // vec.push_back(3);
  // vec.push_back(9);
  // vec.push_back(3);
  // vec.push_back(2);
  // vec.push_back(1);

  //number is 713322
  vec.push_back(7);
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(3);
  vec.push_back(2);
  vec.push_back(2);

  print(vec);
  NextSmallestPalindrome(vec);
  print(vec);

  return 1;
}
