// hume i and j dia hoga jo range bataega 
// suppose 1111 01101110 111 hume beech vale ko clear karna hai aur ise 111100000000111 banana hai
// to iske do mask banaenge pehla : 111100000000000    dusra: 000000000000111
// fir inn dono masks ka OR kar denge

#include<iostream>

using namespace std;

int main()
{
    int n=15;
    int i=2;
    int j=1;
    int a=(-1<<(i+1));          // -1 ki value 1111...1111 hoti hai to hum jab use i+1 times shift karenge to uske aage utne hi zeros aa jaenge 
    int b=(1<<j)-1;             // 1 ko j times left shift kardo eg-> 000001 hai to use agar hum 3 baar right shift kare to 000001000 aaega aur fir agar usme se hum 1 minus kar le to 000000111 aaega (first set bit from right zero ho jaegi aur usse pehle ke saare zero 1 ho jaenge )
    int mask=a|b;
    int ans=n&mask;
    cout<<ans;
    return 0;
}