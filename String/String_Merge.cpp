#include <iostream>
#include <string>
using namespace std;

string StringMerge(string str) {

int count=0;
for(int i=0;i<str.length();i++)
{
    if(str[i]=='*')
    {
        break;    
    }
    else{
        count++;
    }
}
  string str1="";
  string str2="";
  for(int i=0;i<count;i++)
  {
    str1=str1+str[i];
  }
for(int i=count+1;i<str.length();i++) 
  {
    str2+=str[i];
  }
  string ans="";
  int len1=0;
  int len2=0;
  while(len1<str1.length() &&  len2<str2.length())
  {
    ans=ans+str1[len1];
    ans=ans+str2[len2];
    len1++;
    len2++;
  }
  return ans;

}

int main(void) { 
   
  // keep this function call here
  string str="aaa*bbb";
  cout<<StringMerge(str);
  return 0;
    
}