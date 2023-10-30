#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{   
    //creation
    unordered_map<string,int>m;
    //insertion
    pair<string,int>p=make_pair("Scorpio",9);
    m.insert(p);

    pair<string,int>p2("alto",2);
    m.insert(p2);
    
    m["fortuner"]=10;

    //access
    cout<<m.at("alto")<<endl;
    cout<<m.at("Scropio")<<endl;

    cout<<m["fortuner"]<<endl;

    //search
    cout<<m.count("Scorpio");
    if(m.find("fortuner")!=m.end())
    {
        cout<<"fortuner found"<<endl;
    }
    else{
        cout<<"Fortuner not found"<<endl;
    }
    cout<<m.size();
    cout<<m["hummer"]<<endl;

    //iteration
    for(auto i:m)
    {
        cout<<i.first<<"-> "<<i.second<<endl;
    }
    
    return 0;
}