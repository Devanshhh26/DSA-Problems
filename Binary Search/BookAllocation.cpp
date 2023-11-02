/*
ek array hai n books ki aur har array ke index pe uss book ke number of pages kitne hai dia hua hai
m hai number of student
hume unn books ko among m students distribute karna hai with following conditions
1. har student ko atleast 1 book to mile 
2. ek book sirf ek hi student ko mil sakti hai aesa nahi ho sakta ki ek book ke thode pages ek student padh raha hai aur thode pages dusra student
3. agar ek student ko multiple books mil rahi hai to vo saari books continous honi chahiye that is agar ek bande ko a[i] book mili hai to use agli book a[i+1] milni chahiye na ki a[i+2]

our task is to minimize the maximum number of pages a student reads
*/
/*
to solve this question hum pehle saare elements ka sum nikal lenge aur end me store karwa lenge fir binary search lagaenge 0 se end tak
aur mid nikalenge aur hum mid ko as max pages jo hum allocate karenge uski tarah treat karenge

fir ekfunction banaenge check karne ke lie ki jo humne max pages consider kie hai vo possible bhi hai ya nahi
function me hum har page ka book ke pages ka sum karenge agar sum max pages se upar chale jae to fir next student ko de denge ko book
but agar aesa hua ki total pages jo hai book ke vo reh gae end me but students khatam ho gae iska matlab humne kam pages allocate kie the
islye hum function se return false kar denge aur start = mid + 1 karke firse call karenge function ko 
agar sab sahi raha to hum answer ko store karwa lenge aur firse function ko call karenge end=mid -1 karke kyoki hume answer ko
minimize karna hai to yeh possibility hai ki isse bhi chota answer exist karta ho

hum answer ko aur optimize kar sakte hai agar start ko hum 0 ki jagah array me jo maximum number of pages hai usse initialize kare
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

bool isPossible(int res[],int N,int M,int maxPages)
{
    int pageSum=0;                  // starting me sum of pages 0 hoga
    int student=1;                  // student ko 1 se intialise kar denge
    for(int i=0;i<N;i++)
    {
        if(res[i]>maxPages)         // agar res[i] bada ho max number if pages jo hum allot kar sakte hai usse to retun false kar denge
        {
            return false;
        }
        if(pageSum+res[i]>maxPages)     // agar abhi tak jitne bhi pages allocate hue hai student ko + jo next book ke pages allot hone jaa rahe hai unka sum agar max pages se zyada ho jae matlab hum new book allocate nahi kar sakte uss student ko isliye next student ko allocate karenge book 
        {
            student++;                  // student ++ kar dia kyoki ab next student koi book allocate hogi
            pageSum=res[i];             // page sum ko reset karke new book ke pages ke equal kar dia
            if(student>M)               // agar students total number of students se bada ho jae iska humne kam pages allot kar rakhe hai isliye return false
            {
                return false;
            }
        }
        else{
            pageSum=pageSum+res[i];     // agar sab kuch sahi raha to hum pages ke sum ko new book ke pages se update kar denge
        }
    }
    return true;
}

int main()
{   
    int res[]={12,34,67,90};
    int N=4;                                // total number of books
    int M=2;                                // total number of students
    int start=0;  
    int end=accumulate(res,res+N,0);        // sum of all the pages of the books
    int ans=-1;
    
    while(start<=end)
    {   int mid=start+(end-start)/2;        // max pages we can allocate
        if(isPossible(res,N,M,mid))         // agar yeh possible answer hue to ise store kar lenge
        {
            ans=mid;                        // possible answer store kar lia
            end=mid-1;                      // but kya pata isse chota bhi koi answer exist karta ho isliye end ko mid-1 kar denge
        }
        else{
            start=mid+1;                    // iska matlab jo humne max pages allocate kiye the vo kam hai isliye start ko aage badao
        }
    }
    cout<<"Minimum number of pages to be allocated : "<<ans;
    return 0;
}