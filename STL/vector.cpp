#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#define pb push_back
using namespace std;
void display(vector<int> &vec){
	if(vec.empty()){
		cout<<endl<<"The vector is empty!!";
		return;
	}
	cout<<endl<<"---------Vector Display called---------"<<endl;
	for(int a: vec){
		cout<<a<<" , ";
	}
}
void fillRandomValues(vector<int> &vec, int noOfValuesToBeFilledInVector){
	cout<<endl<<noOfValuesToBeFilledInVector<<" values would be filled in vector";
	for(int i=0;i<noOfValuesToBeFilledInVector;i++){
		// vec.pb(rand()%2000); works because given in above define
		vec.push_back(rand()%2000);
	}
	display(vec);
}
bool compareBasedOnModulo13(int a, int b){
	int aMod13=a%13;
	int bMod13=b%13;
	return aMod13<bMod13;
}
int main(){

	vector<int> v;
	fillRandomValues(v,20);


	//possible ways of initialization
	//0
	// Create a vector of size n here 3 with all values as 10.
	int n=3;
  vector<int> vect(n, 10);
	display(vect);
	//1
	vector<int> vect2(v.begin(), v.end());
	//2
	int arr[] = { 10, 20, 30 };
  int n1 = sizeof(arr) / sizeof(arr[0]);
 	vector<int> vect3(arr, arr + n1);


	//can also traverse using iterators
	cout<<endl<<"---------Vector Display using iterators called---------"<<endl;
	for(auto i=v.begin();i!=v.end();i++){
		cout<<*i<<" ";
	}

	//to know number of elements use size()
	cout<<endl<<"No of elements in the vector are :- "<<v.size();

	//to remove elements from back we can use pop_back();
	cout<<endl<<"Last element is removed now:- ";
	v.pop_back();
	display(v);
	cout<<endl<<"No of elements in the vector are :- "<<v.size();

	//to erase all data use clear();
	cout<<"Erased all data";
	v.clear();
	display(v);
	cout<<endl<<"No of elements in the vector are :- "<<v.size();


	//to access element at index i either use v[i] or v.at(i)
	fillRandomValues(v,5);
	cout<<endl<<"Value at index 2 :- "<<v[2];
	cout<<endl<<"Value at index 4 :- "<<v.at(4);

	//sorting a vector
	sort(v.begin(),v.end());
	cout<<endl<<"Sorted vector in ascending order :-";
	sort(v.begin(),v.end(),greater<int>());
	display(v);
	cout<<endl<<"Sorted vector in descending order :-";
	display(v);
	cout<<endl<<"Mod of 13 for all elements";
	for(int i:v){
		cout<<endl<<i<<" --> "<<i%13;
	}
	cout<<endl<<"Sorted in custom order";
	sort(v.begin(),v.end(),compareBasedOnModulo13);
	display(v);

	return 1;
}

/*
O/P

20 values would be filled in vector
---------Vector Display called---------
807 , 1249 , 73 , 1658 , 930 , 1272 , 1544 , 878 , 1923 , 1709 , 440 , 165 , 492 , 1042 , 1987 , 503 , 327 , 1729 , 840 , 612 ,
---------Vector Display called---------
10 , 10 , 10 ,
---------Vector Display using iterators called---------
807 1249 73 1658 930 1272 1544 878 1923 1709 440 165 492 1042 1987 503 327 1729 840 612
No of elements in the vector are :- 20
Last element is removed now:-
---------Vector Display called---------
807 , 1249 , 73 , 1658 , 930 , 1272 , 1544 , 878 , 1923 , 1709 , 440 , 165 , 492 , 1042 , 1987 , 503 , 327 , 1729 , 840 ,
No of elements in the vector are :- 19Erased all data
The vector is empty!!
No of elements in the vector are :- 0
5 values would be filled in vector
---------Vector Display called---------
303 , 1169 , 1709 , 1157 , 1560 ,
Value at index 2 :- 1709
Value at index 4 :- 1560
Sorted vector in ascending order :-
---------Vector Display called---------
1709 , 1560 , 1169 , 1157 , 303 ,
Sorted vector in descending order :-
---------Vector Display called---------
1709 , 1560 , 1169 , 1157 , 303 ,
Mod of 13 for all elements
1709 --> 6
1560 --> 0
1169 --> 12
1157 --> 0
303 --> 4
Sorted in custom order
---------Vector Display called---------
1560 , 1157 , 303 , 1709 , 1169 ,

*/
