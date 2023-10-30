// largest 0 and 1 subarray nikalni hai

// can be converted into largest subarray with zero sum by replacing 0 with -1 aur fir hume largest subarray with 0 sum nikalna hoga kyoki 1 aur -1 add hoke 0 denge
// aur same code fir hum laga sakte hai

/*
 int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mp;
        int csum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int val=A[i]==0?-1:1;           // 0 ko -1 me convert kar dia
            csum+=val                        // cummulative sum nikala uss element ka
            if(csum==0)                         // agar cummulative sum hi 0 ho gaya to check krenge max len ke lie
            {
                ans=max(ans,i+1);
            }
            else if(mp.find(csum)==mp.end())        // agar map me vo sum present nahi ha to map me daal do sum aur uska index
            {
                mp[csum]=i;
            }
            else{                                   // agart map me exist karta hai to use check karo max len ke lie by subtracting new index with old index
                ans=max(ans,i-mp[csum]);
            }
        }
        return ans;
    }
*/