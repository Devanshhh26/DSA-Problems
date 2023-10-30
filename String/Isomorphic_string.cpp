#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "egg";
    string t = "add";
    int hash[256] = {0};
    bool istCharsMapped[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] == 0 && istCharsMapped[t[i]] == 0)               // check if it is already mapped if not then map it
        {
            hash[s[i]] = t[i];                                         // e->a and g->d and the other g will not be mapped because e is already mapped
            istCharsMapped[t[i]] = true;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] != t[i])                                       // check if the mapped characters are same for each
        {                                                             // lets say if s=egg and t=ads then e->a , g->d and then g->s but g is not mapped to s rather it is mapped to g therefor false
            cout << "False";
            return 0;
        }
    }
    cout << "True";
    return 0;
}