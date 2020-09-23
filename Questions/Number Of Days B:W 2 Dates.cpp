#include <iostream>
#include <math.h>
using namespace std;
//Given 2 dates find the no. of days bw the 2
const int NumberOfDaysInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
struct date{
  int y;//YYYY
  int d;//DD
  int m;//MM
};
int NumberOfLeapYearsTillYear(const date & obj){
  int ans=0,year;
  if(obj.m<=2){
    //don't count this year if month is less than march
    year=obj.y-1;
  }
  else{
    //count this year if month is greater than february
    year=obj.y;
  }
  ans=year/4 + year/400 - year/100;
  //to be a leap year a year must be divisible by 4
  //but if it is divisible by 100 then only a leap year if also divisible by 400 otherwise not
  return ans;
}
void DateDiff(date d1,date d2){
  long int days1=0,days2=0;
  //calculate number of days for d1 wrt 00/00/0000
  days1+=d1.y*365;
  for(int i=0;i<d1.m-1;i++){
    days1+=NumberOfDaysInMonth[i];
  }
  days1+=d1.m;
  days1+=NumberOfLeapYearsTillYear(d1);
  //calculate number of days for d2 wrt 00/00/0000
  days2+=d2.y*365;
  for(int i=0;i<d2.m-1;i++){
    days2+=NumberOfDaysInMonth[i];
  }
  days2+=d2.m;
  days2+=NumberOfLeapYearsTillYear(d1);
  //return difference as answer
  long int years,days,ans=abs(days1-days2);
  days=ans%365;
  years=ans/365;
  cout<<endl<<"The difference B/W to dates is "<<ans;
  cout<<endl<<"Which is equal to "<<years<<" Years and "<<days<<" Days"<<endl;
}
int main(){
  date d1,d2;
  d1.d=30;
  d1.m=8;
  d1.y=1964;

  d2.d=23;
  d2.m=9;
  d2.y=2020;

  DateDiff(d1,d2);
  return 1;
}
