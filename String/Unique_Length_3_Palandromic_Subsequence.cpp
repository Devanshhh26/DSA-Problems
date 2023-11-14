// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

/*

agar hume 3 length ke palandromic subsequence nikalne hai to hum ek set lenge jisme jo jo element hum process karte jaenge unhe store krenge kyoki hume unique patterns hi chahiye sirf
to hum string ka pehla letter uthange aur fir string ke end se uske jaisa similar element search karenge aur fir dono ke index store kar lenge
agar hume 3 length ka palindromic subsequence chahie to pehla aur last character to same hona compulsory hai jo humne already find kar lia hai
ab hum sirf sirf first aur last character ke beech me jitne bhi unique elements aa rahe hai unka count nikalna hai kyoki utne hi palandromic subsequence ban paenge
unique character nikalne ke lie hum set ka use kar sakte hai

*/

class Solution {
public:

    int isUnique(string s,int start,int end)
    {
        set<char>unique;
        --end;
        while(start<end)
        {
            unique.insert(s[end]);                  // set sirf unique elements store karega
            end--;
        }
        return unique.size();                      // set ka size return kardo iska matlab start aur end ke beech me set ka jo size hai utne unique elements aate hai
    }

    int countPalindromicSubsequence(string s) {
        set<char>st;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s[i])==st.end())             // agar character set me nahi hai it means abhi tak uss jaesa koi element nahi aaya hai
            {                                    
                st.insert(s[i]);                    // use set me insert kar do
                int start=i;                        // uska index store karlo
                int end=-1;                         
                for(int j=s.length();j>=0;j--)      // string ke end se uske jaisa same character search karlo
                {
                    if(s[j]==s[i])
                    {
                        end=j;                      // index store karlo uss element ka
                        break;
                    }
                }
                int res=isUnique(s,start,end);      // total number of unique element nikal lo jo s[i] se ban sakte hai that is start aur end ke beech ke unique elements
                ans=ans+res;                        // final answer me add karlo iss character se jitne bhi palandromic subsequence bane 
            }
        }
        return ans;
    }
};