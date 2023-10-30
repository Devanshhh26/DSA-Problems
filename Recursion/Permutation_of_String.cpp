#include<iostream>
#include<string>
using namespace std;

void permutation(string& s, int i)
{
    if(i>=s.length())
    {
        cout<<s<<" ";
        return;
    }
    for(int j=i;j<s.length();j++)
    {   // Swapping
        swap(s[i],s[j]);
        // Recursion
        permutation(s,i+1);
        // Backtracking - since we are passing the address of string therefore we need to change it again back to original string
        swap(s[i],s[j]);
    }

}

int main()
{
    string s="abc";
    int i=0;
    permutation(s,i);
    return 0;   
}