// ek baar roman army ne jewish army ko gher lia tha to jewish army vale log ek cave me chup gae the
// jewish army ke 40 log bache the aur unhone socha ki romans ke haatho marne se achcha hai ki apas me ek dusre ko maar lete hai
// but 40 logo me ek end me banda bachega jise suicide karna padega to end me kaun bachna chahega
// tab josephus aaya aur bola hum sab ek circle me khade ho jaate hai fir count karenge 7 tak aur jisme bhi 7 aaya use maar denge 
// aur aur fir count uske next person se restart karenge, jab yeh process pura ho jata hai to end me josephus bachta hai
// aur josephus surreneder kar deta hai suicide ki jagah , log kehte hai usne yeh jaanboojhkar kia tha aur usne pehle hi calculate kar 
// lia tha ki kaunse number pe vo khada hoga to vo end me zinda bachega recursion ke through

// ab hume vo position find karni hai initial circle me ki jisme khade honge to end tak bachenge

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>res,int k,int idx,int& ans)
{
    if(res.size()==1)                   // jab vector ka size 1 reh jae to matlab answer mil gaya hai
    {
        ans=res[0];
        return ;
    }
    idx=(idx+k)%res.size();             // jo remove hone vala hai uska index nikal lo
    res.erase(res.begin()+idx);         // use remove kardo
    solve(res,k,idx,ans);               // recursive call maardo

}

int main()
{
    int n=40;
    int k=7;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        res.push_back(i+1);             //1 se n tak saare elements insert kardo
    }
    k--;                                // vector ka index 0 se hai isliye
    int idx=0;
    int ans=-1;
    solve(res,k,idx,ans);
    cout<<ans;
    return 0;
}