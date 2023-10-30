
//https://leetcode.com/problems/valid-palindrome-ii/


#include<iostream>
#include<string>
using namespace std;
bool checkPalindrome(string s,int low,int high)
{
    while(low<=high)
    {
        if(s[low]==s[high])
        {
            low++;
            high--;
        }
        else{
            return false;
        }
    }
}
int main()
{
   string s="leverl";
   int low=0;
   int high=s.length()-1;
   while(low<=high)
   {
    if(s[low]!=s[high])
    {
        return checkPalindrome(s,low+1,high) || checkPalindrome(s,low,high-1);
    }
    else{
        low++;
        high--;
    }
   } 
   return true;
}