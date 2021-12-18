38. Count and Say

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character.
Then for each group, say the number of characters, then say the character. To convert the saying into a digit string,
replace the counts with a number and concatenate every saying.


Given a positive integer n, return the nth term of the count-and-say sequence.

Example 1:
Input: n = 1
Output: "1"
Explanation: This is the base case.

Example 2:
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

Hints
To generate the nth term, just count and say the n-1th term.
The following are the terms from n=1 to n=10 of the count-and-say sequence:
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221



Code-
string countAndSay(int n){
        if(n==1){
            return "1";
        }
        char ch[10]={'0','1','2','3','4','5','6','7','8','9'};
        string nSePehle=countAndSay(n-1);
        string ans="";
        char digit;
        int count=0;
        for(int i=0;i<nSePehle.length();){
            digit=nSePehle[i];
            count=1;
            int j=i+1;
            while(j<nSePehle.length() and nSePehle[j]==digit){
                count++;
                j++;
            }
            cout<<"count "<<count<<" for character "<<digit;
            ans+=ch[count];
            ans+=digit;
            i=j;
        }
        return ans;
    }

TC-O(n*k) where n is the input number and k is the maximum length of the number in string format
SC-O(n) due to the recursive call stack
