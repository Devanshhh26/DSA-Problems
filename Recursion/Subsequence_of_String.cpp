#include<iostream>
#include<vector>
using namespace std;
void printSubsequence(string str,string output,int i,vector<string>&v)
{   
    if(i>=str.length())
    {   
        //storing int vector
        v.push_back(output);
        return;
    }

    //Exclude

    printSubsequence(str,output,i+1,v);
    
    //Include
    
    output=output+str[i];
    printSubsequence(str,output,i+1,v);
}
int main()
{
    string str="abc";
    string output="";
    vector<string>v;
    int i=0;
    printSubsequence(str,output,i,v);
    int count=0;
    for(auto val : v)
    {
        cout<<val<<" ";
        count++;
    }
    cout<<count;
    return 0;

}